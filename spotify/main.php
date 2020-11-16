<!DOCTYPE html>
<html lang="ja">
<head>
	<meta charset="utf-8">
	<title>spotify manager</title>
        <link rel=stylesheet href="styles.css">
</head>
<body>
<?php
require 'vendor/autoload.php';
$session = new SpotifyWebAPI\Session(
	'511d24499f014e2b8eb0b8b7e0fbb04f',
	'4dd24eb2caa34090b736f827785e2dd0',
	'http://localhost/spotify/main.php/'
);
$api = new SpotifyWebAPI\SpotifyWebAPI();
try{
	$session->requestAccessToken($_GET['code']);
}catch(Exception $e){
	print_r($e);
	exit ;
}
?>
<header>spotify manager</header>
<?php
$api->setAccessToken($session->getAccessToken());
$me = $api->me();
$playlists = $api->getUserPlaylists($me->id, []);
foreach ($playlists->items as $playlist) {
	echo '<a href="' . $playlist->external_urls->spotify . '">' . $playlist->name . '</a> <br>';
}

?>
<footer>
<?php
	$me = $api->me();
	echo $me->display_name;
?>
</footer>
</body>
</html>
