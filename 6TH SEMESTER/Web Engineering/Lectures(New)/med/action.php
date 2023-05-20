<?php
if (session_status() === PHP_SESSION_NONE)
session_start();
require_once('./db-connect.php');
Class Action{
    public $conn;
    function __construct(){
        global $conn;
        $this->conn = $conn;
    }
    function __destruct(){
        $this->conn->close();
    }
    public function save_file(){
        extract($_POST);
        $data = "";
        foreach($_POST as $k => $v){
            if(!is_array($_POST[$k]) && !in_array($k,['id','content'])){
                $v = $this->conn->real_escape_string($v);
                if(!empty($data)) $data .= ", ";
                $data .= " `{$k}` = '{$v}'";
            }
        }
        $check = $this->conn->query("SELECT * FROM `file_list` where `name` = '{$name}' ".(!empty($id) ? " and id != '{$id}' " : '')." ")->num_rows;
        if($check > 0){
            $resp['status'] = 'failed';
            $resp['msg'] = "{$name} File Name already exists.";
        }else{
            if(empty($id)){
                $sql = "INSERT INTO `file_list` set {$data}";
            }else{
                $sql = "UPDATE `file_list` set {$data} where id = '{$id}'";
            }
            $save = $this->conn->query($sql);
            if($save){
                $fid = empty($id) ? $this->conn->insert_id : $id ;
                $get = $this->conn->query("SELECT * FROM `file_list` where id = '{$id}'")->fetch_array();
                $filename = strtolower(str_replace(' ', '_', $name));
                $cfname = 'contents/'.$filename.'.html';
                $pfname = 'pdfs/'.$filename.'.pdf';
                $put_content = file_put_contents($cfname, $content);
                if($put_content){
                    $this->conn->query("UPDATE `file_list` set file_path = '{$cfname}' where id = '{$fid}'");
                }
                if(isset($get['pdf_path'])){
                    unlink("./".$get['pdf_path']);
                }
                $make_pdf  = $this->create_pdf_file($fid, $pfname);
                if($make_pdf)
                    $this->conn->query("UPDATE `file_list` set pdf_path = '{$pfname}' where id = '{$fid}'");
                $_SESSION['msg']['type'] = 'success';
                if(empty($id))
                    $_SESSION['msg']['text'] = 'File has been added successfully.';
                else
                    $_SESSION['msg']['text'] = 'File has been updated successfully.';
                $resp['status'] = 'success';
            }else{
                $resp['status'] = 'failed';
                $resp['msg'] = "{$name} File Name already exists.";
            }
        }
        return json_encode($resp);
    } 
    public function save_record(){
        extract($_POST);
        $data = "";
        // foreach($_POST as $k => $v){
        //     if(!is_array($_POST[$k]) && !in_array($k,['id'])){
        //         $v = addslashes($this->conn->real_escape_string($v));
        //         if(!empty($data)) $data .= ", ";
        //         $data .= " `{$k}` = '{$v}'";
        //     }
        // }
        if(empty($id)){
            $code_prefix = date("Ymd")."-";
            $code = 1;
            while(true){
                $tmp_code = $code_prefix. (sprintf("%'.05d",$code));
                $check_code = $this->conn->query("SELECT `id` FROM `med_cert_info` where `code` = '{$tmp_code}'")->num_rows;
                if($check_code > 0){
                    $code++;
                }else{
                    $code = $tmp_code;
                    if(!empty($data)) $data .= ", ";
                     $data .= " `code` = '{$code}'";
                    break;
                }
            }
        }
        if(isset($firstname) && isset($middlename) && isset($lastname) && isset($suffix)){
            $fullname = $lastname.(!empty($suffix)? " {$suffix}" : "").", ".$firstname." ".(!empty($middlename)? " {$middlename}" : "");
            if(!empty($data)) $data .= ", ";
             $data .= " `fullname` = '{$fullname}'";
        }
        if(empty($id)){
            $sql = "INSERT INTO `med_cert_info` set {$data}";
        }else{
            $sql = "UPDATE `med_cert_info` set {$data} where id = '{$id}'";
        }
        $save = $this->conn->query($sql);
        if($save){
            $rid = empty($id) ? $this->conn->insert_id : $id ;
            $mdata= "";
            foreach($_POST as $k => $v){
                if(!is_array($_POST[$k]) && !in_array($k, ['id', 'code', 'fullname'])){
                    if(!is_numeric($v)){
                        $v = addslashes($this->conn->real_escape_string($v));
                    }
                    if(!empty($mdata)) $mdata .= ", ";
                    $mdata .= "('{$rid}', '{$k}', '{$v}')";
                }
            }

            $delete_meta = $this->conn->query("DELETE FROM `med_cert_info_meta` where `med_cert_info_id` = '{$rid}'");
            // print_r($mdata);exit;
            if(!empty($mdata)){
                $meta_sql = "INSERT INTO `med_cert_info_meta` (`med_cert_info_id`, `meta_key`, `meta_value`) VALUES {$mdata}";
                $meta_batch_insert = $this->conn->query($meta_sql);
                if(isset($this->conn->error) && !empty($this->conn->error)){
                    if(empty($id)){
                        $this->conn->query("DELETE FROM `med_cert_info` where `id` = '{$rid}'");
                    }
                    return json_encode([
                        'status' => 'failed',
                        'msg' => $this->conn->error
                    ]);
                }
            }
            if(!is_dir('./med_cert_pdfs')){
                mkdir('./med_cert_pdfs');
            }
            $code = $this->conn->query("SELECT `code` FROM `med_cert_info` where `id` = '{$rid}'")->fetch_assoc()['code'];
            $med_cert_pdf_fname = $code.".pdf";
            if(is_file("./med_cert_pdfs/{$med_cert_pdf_fname}"))
            unlink("./med_cert_pdfs/{$med_cert_pdf_fname}");

            $make_pdf  = $this->create_pdf_file($rid, "med_cert_pdfs/{$med_cert_pdf_fname}");
            // $make_pdf  = false;
            $_SESSION['msg']['type'] = 'success';
            if(empty($id))
                $_SESSION['msg']['text'] = 'Medical Certificate Details has been added successfully.';
            else
                $_SESSION['msg']['text'] = 'Medical Certificate Details has been updated successfully.';
            if(!$make_pdf){
                $_SESSION['msg']['text'] .= 'But failed to generate the medical certificate file due to unknown reason.';
            }else{
                $resp['view_path'] = "./med_cert_pdfs/{$med_cert_pdf_fname}";
            }

            $resp['status'] = 'success';
        }else{
            $resp['status'] = 'failed';
            $resp['msg'] = "{$name} File Name already exists.";
        }
        return json_encode($resp);
    } 

    function create_pdf_file($rid, $pfname){
        if(!empty($rid)){
            $qry = $this->conn->query("SELECT * FROM `med_cert_info` where id = '{$rid}' ");
            foreach($qry->fetch_array() as $k => $v){
                if(!is_numeric($k)){
                    $$k = $v;
                }
            }
            if(isset($id)){
                $meta_qry = $this->conn->query("SELECT * FROM `med_cert_info_meta` where `med_cert_info_id` = '{$id}'");
                if($meta_qry->num_rows > 0){
                    $meta = array_column($meta_qry->fetch_all(MYSQLI_ASSOC), 'meta_value', 'meta_key');
                }
            }
            try{
                include_once 'generate_pdf.php';
                return true;
            }catch(Exception $e){
                return $e;

            }
        }else{
            return false;
        }
    }
    function delete_record(){
        extract($_POST);
        $qry = $this->conn->query("SELECT * FROM `med_cert_info` where id = '{$id}' ");
        if($qry->num_rows > 0){
            $data = $qry->fetch_array();
            $delete = $this->conn->query("DELETE FROM `med_cert_info` where id = '{$id}'");
            if($delete){
                if(is_file("./med_cert_pdfs/{$data['code']}.pdf"))
                    unlink("./med_cert_pdfs/{$data['code']}.pdf");
                
                $_SESSION['msg']['type'] = 'success';
                $_SESSION['msg']['text'] = 'Medical Certificate Record has been deleted successfully.';
                $resp['status'] = 'success';
            }
        }else{
            $resp['status'] ='failed';
            $resp['msg'] ='Unknown File ID';
        }
        return json_encode($resp);

    }
} 

$action  = new Action();
$a = isset($_GET['action']) ? $_GET['action'] : '';
switch($a){
    case 'save_record':
        echo $action->save_record();
        break;
    case 'delete_record':
        echo $action->delete_record();
        break;
    default:
        echo 'No Action';
        break;
}