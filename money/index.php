<!DOCTYPE html>
<html lang="ja">
    <head>
        <title>money</title>
        <meta charset="utf-8">
    </head>
    <body>
        <input id="des" placeholder="項目を入力">
        <input id="yen" placeholder="金額を入力" onkeypress="keypress()">
        <button onclick="submit()">OK</button>
        <?php
            $database = mysqli_connect('localhost', 'payoff');
            $res = mysqli_query($database,'SELECT * FROM payoff.money');
            $sum = 0;
            foreach($res as $row){
                echo '<p>'.$row['des']." ".$row['yen'].'</p>';
                $sum+=$row['yen'];
            }
            echo '<p>'.'合計は ¥'.$sum.'</p>';
        ?>
    </body>
    <script type="text/javascript">
        function keypress(){
            if( window.event.keyCode == 13 ){
                submit();
            }
        }
        function submit(){
            var des=document.getElementById('des').value;
            var yen=document.getElementById('yen').value;
            var contents={des:des,yen:yen};
            
            var request = createXmlHttpRequest();
            request.open('POST','./receiver.php',true);
            request.setRequestHeader("Content-Type","application/json");
            request.addEventListener('load',function(response){
                console.log(this.responseText);
            });
            request.send(JSON.stringify(contents));
        }
        function createXmlHttpRequest(){
            var xmlhttp=null;
            if(window.ActiveXObject) {
            try {
                xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
                } catch(e) {
                        try {
                            xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
                        } catch (e2) {}
                    }
                }
            else if(window.XMLHttpRequest) {
                xmlhttp = new XMLHttpRequest();
            }
            return xmlhttp;
        }
    </script>
</html>