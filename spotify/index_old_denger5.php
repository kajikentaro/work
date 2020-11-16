<?php
require 'vendor/autoload.php';

$session = new SpotifyWebAPI\Session(
	'511d24499f014e2b8eb0b8b7e0fbb04f',
	'4dd24eb2caa34090b736f827785e2dd0',
	'http://localhost/spotify/index_old_denger5.php'
);

$api = new SpotifyWebAPI\SpotifyWebAPI();

/*
 * わたしの Spotify プロフィール：testacounts89.0
https://open.spotify.com/user/s1pfbd43e2xtfahw4pcuyxea0?si=ImhdMnn_S8Ky9oR_TXfT1g

わたしの Spotify プロフィール：testacounts890
https://open.spotify.com/user/testacounts890?si=M1UOeQuaRz28JDN_MOTsNw

わたしの Spotify プロフィール：fio
https://open.spotify.com/user/4bl01hplppqdqrsl77q272mwb?si=0rRf8KV5RdSr0puQzD5vSQ

わたしの Spotify プロフィール：superbeaconhumstar
	https://open.spotify.com/user/superbeaconhumstar?si=0jAtrYKKROaYduHKX8_fuw
 */
if ($_GET['code']) {
	$session->requestAccessToken($_GET['code']);
	$api->setAccessToken($session->getAccessToken());
/*
	$fio= $api->getUserPlaylists('4bl01hplppqdqrsl77q272mwb', [
	]);
	foreach ($fio->items as $playlist) {
		echo '<a href="' . $playlist->external_urls->spotify . '">' . $playlist->name . '</a> <br>';
	}
 */
	$super= $api->getUserPlaylists('superbeaconhumstar', ['limit'=>33
	]);
	foreach ($super->items as $playlist) {
		$response = $api->createPlaylist([
		    'name' => $playlist->name . 'super'
		]);
		$playlistTracks = $api->getPlaylistTracks($playlist->id);
		$track_id_array = array();
		foreach ($playlistTracks->items as $track) {
		    $track = $track->track;
		    array_push($track_id_array,$track->id);
		}
		$api->addPlaylistTracks($response->id, $track_id_array);
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
