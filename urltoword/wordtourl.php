<?php
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
	comment("SQL接続","成功");
	comment("word1",$_GET["word1"]);
	comment("word2",$_GET["word2"]);
	comment("word3",$_GET["word3"]);
	$prepare = $dbh->prepare('SELECT URL FROM urltoword WHERE word1 = ? AND word2 = ? AND word3 = ? ORDER BY id DESC');
	$prepare->bindValue(1,$_GET["word1"],PDO::PARAM_STR);
	$prepare->bindValue(2,$_GET["word2"],PDO::PARAM_STR);
	$prepare->bindValue(3,$_GET["word3"],PDO::PARAM_STR);
	$prepare->execute();
	$result = $prepare->fetch(PDO::FETCH_BOTH);
	print_r($result);
	comment("<br>検出されたURL",$result[0]);
	comment("<br>接続終了","");
} catch (PDOException $e) {
	$error = $e->getMessage();
	comment("接続失敗",$error);
	die("接続に失敗<br>");
}
?>
	
