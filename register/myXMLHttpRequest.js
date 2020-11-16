function createXmlHttpRequest(){
    var xmlhttp=null;
    if(window.ActiveXObject) {
        try {
            xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
        }
        catch(e) {
            try {
                xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
            }
            catch (e2) {
            }
        }
    }
    else if(window.XMLHttpRequest) {
        xmlhttp = new XMLHttpRequest();
    }
    return xmlhttp; 
}