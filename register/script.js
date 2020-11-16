function submit(){
    var contents={};
    var family=document.getElementById("NameFamily");
    var last=document.getElementById("NameLast");
    var family2=document.getElementById("NameFamily2");
    var last2=document.getElementById("NameLast2");
    var select=document.getElementById("select");
    var flag=true;
    if(!(contents.family=family.value)){
        family.style.backgroundColor="#faa";
        flag=false;
    }else{
        family.style.backgroundColor="initial";
    }
    if(!(contents.last=last.value)){
        last.style.backgroundColor="#faa";
        flag=false;
    }else{
        last.style.backgroundColor="initial";
    }
    if(!(contents.family2=family2.value)){
        family2.style.backgroundColor="#faa";
        flag=false;
    }else{
        family2.style.backgroundColor="initial";
    }
    if(!(contents.last2=last2.value)){
        last2.style.backgroundColor="#faa";
        flag=false;
    }else{
        last2.style.backgroundColor="initial";
    }
    if((contents.select=select.value)=="選択してください"){
        select.style.backgroundColor="#faa";
        flag=false;
    }else{
        select.style.backgroundColor="initial";
    }
    if(true){
        var request = createXmlHttpRequest();
        request.open('POST','./receiver.php',true);
        request.setRequestHeader("Content-Type","application/json");
        request.addEventListener('load',function(response){
            console.log(this.responseText);
        });
        request.send(JSON.stringify(contents));
    }
}