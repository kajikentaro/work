<?php
function get_keywords(){
	$keywords = array("apple","grape","orange");
	return $keywords;
}
function comment($tag,$message){
	echo($tag.": ".$message."<br>");
}
try {
	$db_name = "test890_urltoword";
	$dbh = new PDO(
	'mysql:host=mysql1.php.xdomain.ne.jp;dbname=test890_urltoword;charset=utf8',
	'test890_admin',
	'password',
	array(
	    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
	    PDO::ATTR_EMULATE_PREPARES => false,
	)
	);
	comment("SQLサービス接続","成功");
	comment("GET受信データ",$_GET["url"]);
	$keywords = get_keywords();
	$prepare = $dbh->prepare('INSERT INTO urltoword (url, word1, word2, word3) values(?, ?, ?, ?)');
	$prepare->bindValue(1,$_GET["url"],PDO::PARAM_STR);
	$prepare->bindValue(2,$keywords[0],PDO::PARAM_STR);
	$prepare->bindValue(3,$keywords[1],PDO::PARAM_STR);
	$prepare->bindValue(4,$keywords[2],PDO::PARAM_STR);
	$prepare->execute();
	echo("接続終了");
} catch (PDOException $e) {
	$error = $e->getMessage();
	comment("接続失敗",$error);
	die("接続に失敗<br>");
}
?>
