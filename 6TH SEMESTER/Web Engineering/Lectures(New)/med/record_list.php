<div class="py-3">
    <div class="container">
        <h4 class="fw-bolder text-center">Medical Certificate Records</h4>
        <hr>
        <div class="row justify-space-between py-2">
            <div class="col-lg-6 col-md-8 col-sm-12 mx-auto">
                <div class="input-group input-group-dynamic mb-4">
                <span class="input-group-text"><i class="fas fa-search" aria-hidden="true"></i></span>
                <input class="form-control" placeholder="Search" type="search" id="search" >
                </div>
            </div>
        </div>
        <div class="list-group rounded-0" id="record_list">
            <div class="table-responsive">
                <table class="table table-sm table-bordered table-stripped" id="recordsTbl">
                    <colgroup>
                        <col width="10%">
                        <col width="20%">
                        <col width="20%">
                        <col width="30%">
                        <col width="20%">
                    </colgroup>
                    <thead>
                        <tr>
                            <th class="text-center px-1 py-1">#</th>
                            <th class="text-center px-1 py-1">Created</th>
                            <th class="text-center px-1 py-1">Code</th>
                            <th class="text-center px-1 py-1">Name</th>
                            <th class="text-center px-1 py-1">Action</th>
                        </tr>
                    </thead>
                    <tbody>
                    <?php 
                    $records = $conn->query("SELECT * FROM `med_cert_info` order by abs(unix_timestamp(`created_at`)) desc");
                    $i = 1;
                    while($row = $records->fetch_assoc()):            
                    ?>
                        <tr>
                            <td class="text-center"><?= $i++ ?></td>
                            <td><?= date("Y-m-d g:i A", strtotime($row['created_at'])) ?></td>
                            <td><?= $row['code'] ?></td>
                            <td><?= $row['fullname'] ?></td>
                            <td class="text-center">
                                <div class="d-flex w-100 justify-content-center align-items-center">
                                    <?php if(is_file("./med_cert_pdfs/{$row['code']}.pdf")): ?>
                                        <div class="col-auto px-1">
                                            <a href="./med_cert_pdfs/<?= $row['code'] ?>.pdf" target="_blank" download="<?= $row['code'] ?>.pdf" class="text-info" title="Download Med Cert PDF File"><i class="material-icons opacity-6 me-2 text-md">download</i></a>
                                        </div>
                                        <div class="col-auto px-2">
                                            <a href="./med_cert_pdfs/<?= $row['code'] ?>.pdf" target="_blank"  class="text-black" title="View Med Cert"><i class="material-icons opacity-6 me-2 text-md">visibility</i></a>
                                        </div>
                                    <?php endif; ?>
                                    
                                    <div class="col-auto px-2">
                                        <a href="./?page=manage_record&id=<?= $row['id'] ?>" class="text-dark" title="Edit Med Cert Details"><i class="material-icons opacity-6 me-2 text-md">edit</i></a>
                                    </div>
                                    <div class="col-auto px-2">
                                        <a href="javascript:void(0)" data-id="<?= $row['id'] ?>" data-code="<?= $row['code'] ?>" class="text-primary delete_record" title="Edit Med Cert Details"><i class="material-icons opacity-6 me-2 text-md">delete</i></a>
                                    </div>
                                </div>
                            </td>
                        </tr>
                    <?php endwhile; ?>
                    </tbody>
                </table>
            </div>
            
        </div>
        <?php if($records->num_rows <= 0): ?>
            <center><small><em>No PDF record created yet</em></small></center>
        <?php endif?>
        <center id="no_search" style="display:none"><small><em>No Result</em></small></center>

    </div>
</div>
<script>
    $('#search').on('input',function(){
        var search = $(this).val().toLowerCase()
        $('#recordsTbl tbody tr').each(function(){
            if(($(this).text().toLowerCase()).includes(search) === true){
                $(this).toggle(true)
            }else{
                $(this).toggle(false)
            }
        })
        if($('#recordsTbl tbody tr:visible').length > 0){
            $('#no_search').hide()
        }else{
            $('#no_search').show()
        }
    })
    function no_record(){
        alert("Sorry, no record found!")
    }
    $(function(){
        $('.delete_record').click(function(){
            var code = $(this).attr('data-code')
            var id = $(this).attr('data-id')
            if(confirm("Are you sure to delete '"+code+"'?") === true){
                $('.pop-alert').remove()
                var _this = $(this)
                var el = $('<div>')
                el.addClass("pop-alert alert alert-danger text-light")
                el.hide()
                start_loader()
                $.ajax({
                    url:'./action.php?action=delete_record',
                    method:'POST',
                    data:{id : id},
                    dataType:'json',
                error:err=>{
                    console.error(err)
                    el.text("An error occured while deleting data")
                    $('#record_list').parent().prepend(el)
                    el.show('slow')
                    $('html, body').scrollTop($('#record_list').parent().offset().top - '150')
                    end_loader()
                },
                success:function(resp){
                    if(resp.status == 'success'){
                        location.reload();
                    }else if(!!resp.msg){
                        el.text(resp.msg)
                        $('#record_list').parent().prepend(el)
                        el.show('slow')
                        $('html, body').scrollTop($('#record_list').parent().offset().top - '150')
                    }else{
                        el.text("An error occured while deleting data")
                        $('#record_list').parent().prepend(el)
                        el.show('slow')
                        $('html, body').scrollTop($('#record_list').parent().offset().top - '150')
                    }
                    end_loader()
                    console

                }
                })
            }
        })
    })
</script>