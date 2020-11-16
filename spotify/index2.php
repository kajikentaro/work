<link rel=stylesheet href="styles.css">
<?php
require 'vendor/autoload.php';

$session = new SpotifyWebAPI\Session(
	'511d24499f014e2b8eb0b8b7e0fbb04f',
	'4dd24eb2caa34090b736f827785e2dd0',
	'http://localhost/spotify/index2.php/'
);

$api = new SpotifyWebAPI\SpotifyWebAPI();
if ($_GET['code']) {
	$session->requestAccessToken($_GET['code']);
	$api->setAccessToken($session->getAccessToken());
	$me = $api->me();
	$playlists = $api->getUserPlaylists($me->id, []);
	foreach ($playlists->items as $playlist) {
		echo '<a href="' . $playlist->external_urls->spotify . '">' . $playlist->name . '</a> <br>';
	}
} else {
	$options = [
		'scope' => [
			'user-read-email',
			"playlist-read-collaborative",
			"playlist-modify-public",
			"playlist-read-private",
			"playlist-modify-private"
		]
	];

	header('Location: ' . $session->getAuthorizeUrl($options));
	die();
}
?>
