// validate email
// function validateEmail(){
//   var email = document.getElementById("contact-email").value;
//   var reg_exp = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;

//   if(email == "" || email == " "){
//     console.log(email);
//     console.log("false");
//     return false;
//   }

//   if(reg_exp.test(email)){
//     console.log(email);
//     console.log("regexp: true");
//     return true;
//   }
//   else{
//     console.log(email);
//     console.log("regexp: false");
//     return false;
//   }
// }

// validate Name
// function validateName(){
//   var name = document.getElementById("contact-name").value;
//   var reg_exp = /^[A-Za-z ]+$/;

//   if(name == "" || name == " "){
//     console.log("false");
//     console.log(name);
//     return false;
//   }

//   if(reg_exp.test(name)){
//     console.log(name);
//     console.log("regexp: true");
//     return true;
//   }
//   else{
//     console.log(name);
//     console.log("regexp: false");
//     return false;
//   }
// }

// validate
function validateFields()
{
    alert("Click OK button to proceed");
    // var name = document.getElementById("contact-name").value;
    var msg = document.getElementById("contact-message").value;
    window.location.href = "mailto:icetst@nu.edu.pk?subject=Tutorial&body="+msg;
}
