<?php
#$mysqli = new mysqli('localhost', user_name, password, db_name);
$mysqli = new mysqli('localhost',"urltoword","password","urltoword");
if (mysqli_connect_error()){
	echo("接続に失敗");
}else{
	echo("接続に成功");
}
echo($_GET["freedom"]);
?>
	
