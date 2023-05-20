<?php
//============================================================+
// File name   : example_006.php
// Begin       : 2008-03-04
// Last Update : 2013-05-14
//
// Description : Example 006 for TCPDF class
//               WriteHTML and RTL support
//
// Author: Nicola Asuni
//
// (c) Copyright:
//               Nicola Asuni
//               Tecnick.com LTD
//               www.tecnick.com
//               info@tecnick.com
//============================================================+

/**
 * Creates an example PDF TEST document using TCPDF
 * @package com.tecnick.tcpdf
 * @abstract TCPDF - Example: WriteHTML and RTL support
 * @author Nicola Asuni
 * @since 2008-03-04
 */

// Include the main TCPDF library (search for installation path).
require_once('./assets/TCPDF/tcpdf.php');
if(!defined('base_app')) define('base_app', str_replace('\\','/',__DIR__).'/' );
class MYPDF extends TCPDF {
    //Page header
    public function Header() {
        // Logo
        $image_file = base_app.'assets/img/medical-logo.png';
        // print($image_file);exit;
        $this->Image($image_file, 20, 5, 15, '', 'PNG', '', 'T', false, 300, '', false, false, 0, false, false, false);
        // Set font
        $this->SetFont('helvetica', 'B', 20);
        $this->Ln(7);
        // Title
        $this->Cell(0, 15, 'Medical Certificate', 0, false, 'C', 0, '', 0, false, 'M', 'M');
        $this->SetAlpha(.1);
        $this->Image($image_file, 60, 100, 100, 100, "watermark", '', 'T', false, 300, '', false, false, 0, false, false, false);
    }
}
// create new PDF document
$pdf = new MYPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false);
// if($is_encrypted == 1)
// $pdf->SetProtection(array('print', 'copy', 'read'), $password, null, 0, null);
// set document information
$pdf->SetCreator(PDF_CREATOR);
$pdf->SetAuthor('oretnom23');
$pdf->SetTitle((isset($fullname) ? $fullname : "").'- Medical Certificate');
$pdf->SetSubject('Generated Medical Certificate');

// set default header data
// $pdf->SetHeaderData(PDF_HEADER_LOGO, 50, '', '');

// set header and footer fonts
// $pdf->setHeaderFont(Array(PDF_FONT_NAME_MAIN, '', PDF_FONT_SIZE_MAIN));
$pdf->setFooterFont(Array(PDF_FONT_NAME_DATA, '', PDF_FONT_SIZE_DATA));

// set default monospaced font
$pdf->SetDefaultMonospacedFont(PDF_FONT_MONOSPACED);

// set margins
$pdf->SetMargins(PDF_MARGIN_LEFT, PDF_MARGIN_TOP, PDF_MARGIN_RIGHT);
$pdf->SetHeaderMargin(PDF_MARGIN_HEADER);
$pdf->SetFooterMargin(PDF_MARGIN_FOOTER);

// set auto page breaks
$pdf->SetAutoPageBreak(TRUE, PDF_MARGIN_BOTTOM);

// set image scale factor
$pdf->setImageScale(PDF_IMAGE_SCALE_RATIO);

// set some language-dependent strings (optional)
if (@file_exists(dirname(__FILE__).'/lang/eng.php')) {
    require_once(dirname(__FILE__).'/lang/eng.php');
    $pdf->setLanguageArray($l);
}

// ---------------------------------------------------------

// set font
$pdf->SetFont('dejavusans', '', 13);

// add a page
$pdf->AddPage();

// writeHTML($html, $ln=true, $fill=false, $reseth=false, $cell=false, $align='')
// writeHTMLCell($w, $h, $x, $y, $html='', $border=0, $ln=0, $fill=0, $reseth=true, $align='', $autopadding=true)

// create some HTML content
ob_start();
?>
<hr>
<br>
<br>
<div>
    <table cellpadding="2">
        <tr>
            <td width="20%"><span>Fullname: </span></td>
            <td width="30%"><span style="border:1px"><?= isset($fullname) ? $fullname : '' ?></span></td>
            <td width="20%"><span>Gender: </span></td>
            <td width="30%"><span style="border:1px"><?= isset($meta['gender']) ? $meta['gender'] : '' ?></span></td>
        </tr>
        <tr>
            <td><span>Address: </span></td>
            <td colspan="3"><span style="border:1px"><?= isset($meta['address']) ? $meta['address'] : '' ?></span></td>
        </tr>
        <tr>
            <td><span>Birthday: </span></td>
            <td><span style="border:1px"><?= isset($meta['dob']) ? date("F d, Y", strtotime($meta['dob'])) : '' ?></span></td>
            <td><span>Civil Status: </span></td>
            <td><span style="border:1px"><?= isset($meta['civil_status']) ? $meta['civil_status'] : '' ?></span></td>
        </tr>
        <tr>
            <td><span>Nationality: </span></td>
            <td><span style="border:1px"><?= isset($meta['nationality']) ? $meta['nationality'] : '' ?></span></td>
            <td><span>Contact #: </span></td>
            <td><span style="border:1px"><?= isset($meta['contact']) ? $meta['contact'] : '' ?></span></td>
        </tr>
    </table>
    <br>
    <br>
    <br>
    <table cellpadding="2">
        <tr>
            <td width="100%"><span>Diagnostic: </span></td>
        </tr>
        <tr>
            <td colspan="3"><span style="border:1px"><?= isset($meta['diagnostic']) ? $meta['diagnostic'] : '' ?></span></td>
        </tr>
    </table>
    
    <br>
    <hr>
    <br>
    <table cellpadding="2">
        <tr>
            <td width="100%"><span></span></td>
        </tr>
        <tr>
            <td colspan="3">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; I the undersigned, Doctor of Medicine <?= isset($meta['remarks']) ? $meta['remarks'] : "" ?></td>
        </tr>
    </table>
    
    <br>
    <br>
    <br>
    <br>
    <br>
    <br>
    <table cellpadding="2">
        <tr>
            <td width="60%"></td>
            <td width="40%"><p  style="border-bottom:1px solid #000" align="center"><?= (isset($meta['doctor_fullname']) && isset($meta['doctor_suffix'])) ? $meta['doctor_fullname'].(isset($meta['doctor_suffix']) ? ", ".$meta['doctor_suffix'] : "") : "" ?></p></td>
        </tr>
        <tr>
            <td width="60%"></td>
            <td width="40%" align="center">Doctor's Signature Over Printed Name</td>
        </tr>

    </table>    

</div>
<table width="100%" style="table-collapse:collapse" cellspacing="0" cellpadding="1">

</table>

<?php
$html = ob_get_clean();
// $html = file_get_contents('./contents/sample_101.html');

// output the HTML content
$pdf->writeHTML($html, true, false, true, false, '');


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// reset pointer to the last page
$pdf->lastPage();

// ---------------------------------------------------------

//Close and output PDF document
$pdf->Output(base_app.$pfname, 'F');
unset($pdf);

//============================================================+
// END OF FILE
//============================================================+