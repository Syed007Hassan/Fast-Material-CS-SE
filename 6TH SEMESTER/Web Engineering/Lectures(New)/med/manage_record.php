<?php 
if(isset($_GET['id'])){
    $qry = $conn->query("SELECT * FROM `med_cert_info` where id = '{$_GET['id']}'");
    if($qry->num_rows > 0 ){
        foreach($qry->fetch_array() as $k => $v){
            if(!is_numeric($k))
            $$k = $v;
        }
        if(isset($id)){
            $meta_qry = $conn->query("SELECT * FROM `med_cert_info_meta` where `med_cert_info_id` = '{$id}'");
            if($meta_qry->num_rows > 0){
                $meta = array_column($meta_qry->fetch_all(MYSQLI_ASSOC), 'meta_value', 'meta_key');
            }
        }
    }else{
        echo "<script>alert('Unknown given ID')</script>";
    }
}
?>

<section class="py-5">
    <div class="container">
        <h2 class="fw-bolder text-center"><b><?= isset($id) ? "Update Medical Certificate Information" : "Create New Medical Certificate Record" ?></b></h2>
        <hr>
        <div class="row justify-content-center">
            <div class="col-lg-8 col-md-10 col-sm-12 col-xs-12">
                <form action="" id="record-form">
                    <input type="hidden" name="id" value="<?= isset($id) ? $id : '' ?>">
                    <div class="mb-3">
                        <div class="row">
                            <div class="col-lg-4 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  <?= isset($meta['lastname']) ? 'is-filled' : '' ?>">
                                    <label for="lastname" class="form-label">Lastname</label>
                                    <input type="text" id="lastname" name="lastname" value="<?= isset($meta['lastname']) ? $meta['lastname'] : '' ?>" autofocus class="form-control" required="required">
                                </div>
                            </div>
                            <div class="col-lg-4 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  <?= isset($meta['firstname']) ? 'is-filled' : '' ?>">
                                    <label for="firstname" class="form-label">Firstname</label>
                                    <input type="text" id="firstname" name="firstname" value="<?= isset($meta['firstname']) ? $meta['firstname'] : '' ?>" class="form-control" required="required">
                                </div>
                            </div>
                            <div class="col-lg-4 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  <?= isset($meta['middlename']) ? 'is-filled' : '' ?>">
                                    <label for="middlename" class="form-label">Middlename</label>
                                    <input type="text" id="middlename" name="middlename" value="<?= isset($meta['middlename']) ? $meta['middlename'] : '' ?>" class="form-control">
                                </div>
                            </div>
                            <div class="col-lg-4 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  <?= isset($meta['suffix']) ? 'is-filled' : '' ?>">
                                    <label for="suffix" class="form-label">Suffix</label>
                                    <input type="text" id="suffix" name="suffix" value="<?= isset($meta['suffix']) ? $meta['suffix'] : '' ?>" class="form-control">
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  is-filled">
                                    <label for="dob" class="form-label">Birthday</label>
                                    <input type="date" id="dob" name="dob" value="<?= isset($meta['dob']) ? $meta['dob'] : '' ?>" class="form-control" required="required">
                                </div>
                            </div>
                            <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  is-filled">
                                    <label for="gender" class="form-label">Gender</label>
                                    <select id="gender" name="gender" value="<?= isset($meta['gender']) ? $meta['gender'] : '' ?>" class="form-control form-select" required="required">
                                        <option <?= isset($meta['gender']) && $meta['gender'] == "Male" ? "selected" : "" ?>>Male</option>
                                        <option <?= isset($meta['gender']) && $meta['gender'] == "Female" ? "selected" : "" ?>>Female</option>
                                    </select>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  is-filled">
                                    <label for="civil_status" class="form-label">Civil Status</label>
                                    <select id="civil_status" name="civil_status" value="<?= isset($meta['civil_status']) ? $meta['civil_status'] : '' ?>" class="form-control form-select" required="required">
                                        <option <?= isset($meta['civil_status']) && strtolower($meta['civil_status']) == "single" ? "selected" : "" ?>>Single</option>
                                        <option <?= isset($meta['civil_status']) && strtolower($meta['civil_status']) == "married" ? "selected" : "" ?>>Married</option>
                                        <option <?= isset($meta['civil_status']) && strtolower($meta['civil_status']) == "widow" ? "selected" : "" ?>>Widow</option>
                                        <option <?= isset($meta['civil_status']) && strtolower($meta['civil_status']) == "widower" ? "selected" : "" ?>>Widower</option>
                                    </select>
                                </div>
                            </div>
                            <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  <?= isset($meta['contact']) ? 'is-filled' : '' ?>">
                                    <label for="contact" class="form-label">Contact #</label>
                                    <input type="text" id="contact" name="contact" value="<?= isset($meta['contact']) ? $meta['contact'] : '' ?>" class="form-control" required>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  <?= isset($meta['nationality']) ? 'is-filled' : '' ?>">
                                    <label for="nationality" class="form-label">Nationality</label>
                                    <input type="text" id="nationality" name="nationality" value="<?= isset($meta['nationality']) ? $meta['nationality'] : '' ?>" class="form-control" required>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="col-lg-8 col-md-10 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic is-filled">
                                    <label for="address" class="form-label">Address</label>
                                    <textarea type="text" id="address" name="address" class="form-control" required><?= isset($meta['address']) ? $meta['address'] : '' ?></textarea>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="col-lg-8 col-md-10 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic is-filled">
                                    <label for="diagnostic" class="form-label">Doctor's Diagnostic</label>
                                    <textarea type="text" id="diagnostic" name="diagnostic" class="form-control" required><?= isset($meta['diagnostic']) ? $meta['diagnostic'] : '' ?></textarea>
                                </div>
                            </div>
                            <div class="col-lg-8 col-md-10 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic is-filled">
                                    <label for="remarks" class="form-label">Remarks <small class="text-muted">(I the undersigned, Doctor of Medicine)</small></label>
                                    <textarea type="text" id="remarks" name="remarks" class="form-control"><?= isset($meta['remarks']) ? $meta['remarks'] : '' ?></textarea>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  <?= isset($meta['doctor_fullname']) ? 'is-filled' : '' ?>">
                                    <label for="doctor_fullname" class="form-label">Doctor Fullname</label>
                                    <input type="text" id="doctor_fullname" name="doctor_fullname" value="<?= isset($meta['doctor_fullname']) ? $meta['doctor_fullname'] : '' ?>" class="form-control" required>
                                </div>
                            </div>
                            <div class="col-lg-6 col-md-6 col-sm-12 col-xs-12 mb-3">
                                <div class="input-group input-group-dynamic  <?= isset($meta['doctor_suffix']) ? 'is-filled' : '' ?>">
                                    <label for="doctor_suffix" class="form-label">Doctor Suffix</label>
                                    <input type="text" id="doctor_suffix" name="doctor_suffix" value="<?= isset($meta['doctor_suffix']) ? $meta['doctor_suffix'] : '' ?>" class="form-control" required>
                                </div>
                            </div>
                        </div>
                    </div>
                    
                    <div class="row">
                        <div class="col-md-12">
                            <button type="submit" class="btn bg-gradient-dark w-100">Save Record</button>
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>
</section>
<script>
    $(function(){
        
        $('#record-form').submit(function(e){
            e.preventDefault()
            $('.pop-alert').remove()
            var _this = $(this)
            var el = $('<div>')
            el.addClass("pop-alert alert alert-danger text-light")
            el.hide()
            start_loader()
            $.ajax({
                url:'./action.php?action=save_record',
                method:'POST',
                data:$(this).serialize(),
                dataType:'json',
                error:err=>{
                    console.error(err)
                    el.text("An error occured while saving data")
                    _this.prepend(el)
                    el.show('slow')
                    $('html, body').scrollTop(_this.offset().top - '150')
                    end_loader()
                },
                success:function(resp){
                    if(resp.status == 'success'){
                        if(!!resp.view_path){
                            console.log(resp.view_path)
                            window.open(resp.view_path)
                        }
                        location.href= './?page=record_list';
                        // location.reload()
                    }else if(!!resp.msg){
                        el.text(resp.msg)
                        _this.prepend(el)
                        el.show('slow')
                        $('html, body').scrollTop(_this.offset().top - '150')
                    }else{
                        el.text("An error occured while saving data")
                        _this.prepend(el)
                        el.show('slow')
                        $('html, body').scrollTop(_this.offset().top - '150')
                    }
                    end_loader()
                    console

                }
            })
        })
    })
</script>