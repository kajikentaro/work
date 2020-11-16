<!DOCTYPE html>
<html lang="ja">
<head>
	<meta charset="utf-8">
	<title>spotify manager</title>
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
if ($_GET['code']) {
	echo '<p>authorizated</p>';
} else {
	$options = [
		'scope' => [
			'user-read-email',
			'user-read-private',
			"playlist-read-collaborative",
			"playlist-modify-public",
			"playlist-read-private",
			"playlist-modify-private"
		]
	];
	header('Location: '.$session->getAuthorizeUrl($options));
	die();
}
?>
</body>
</html>
