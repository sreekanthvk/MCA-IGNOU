function validate(){
  var str = "Please fill the following fields: \n";
  var flag = true;
  
  if(document.getElementById("stdName").value == ""){
    str += 'Name should not be empty. \n';
    flag = false;
  }
  if(document.getElementById("stdEmail").value == ""){
    str += 'Email should not be empty. \n';
    flag = false;
  }
  if(document.getElementById("stdPhone").value == ""){
    str += 'Phone should not be empty. \n';
    flag = false;
  }
  if(document.getElementById("stdQual").value == ""){
    str += 'Qualification should not be empty. \n';
    flag = false;
  }
  if(document.getElementById("stdProgramme").value == 0){
    str += 'Programme should not be empty. \n';
    flag = false;
  }
  if(!flag){
    alert(str);
    return false;
  }
  return true;
}