<!DOCTYPE html>
<head>
</head>
<button onclick="writeurl()">WRITE URL</button>
<button onclick="readurl()">READ URL</button>
<style>
button{
	font-size:30px;
}
</style>
<script type="text/javascript">
function writeurl(){
	window.location.href="http://localhost/urltoword/urltoword.php?url=test";
}
function readurl(){
	window.location.href="http://localhost/urltoword/wordtourl.php?word1=apple&word2=grape&word3=orange&test=ee";

}
</script>
