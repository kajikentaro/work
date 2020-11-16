<?php
require 'vendor/autoload.php';
$session = new SpotifyWebAPI\Session(
	'511d24499f014e2b8eb0b8b7e0fbb04f',
	'4dd24eb2caa34090b736f827785e2dd0',
	'http://localhost/spotify/index_old_denger2.php'
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
function aaa($input){
	echo('<p>' . $input . '</p>');
}
if ($_GET['code']) {
	$session->requestAccessToken($_GET['code']);
	$api->setAccessToken($session->getAccessToken()); $dot = $api->getUserPlaylists('4bl01hplppqdqrsl77q272mwb', ['limit' => 50]);
	$delmyplay = "";
	aaa(count($dot->items));
	$response = $api->createPlaylist([
	    'name' => 'POP'
	]);
	foreach ($dot->items as $playlist) {
		if(strpos($playlist->name,'pop') !== false){
			$playlistTracks = $api->getPlaylistTracks($playlist->id);
			$track_id_array = array();
			foreach ($playlistTracks->items as $track) {
			    $track = $track->track;
			    array_push($track_id_array,$track->id);
			}
			$api->addPlaylistTracks($response->id, $track_id_array);
		}
		/*
		if(strpos($playlist->name,'EDM') !== false){
			$delmyplay=$playlist->id;
			$playlistTracks = $api->getPlaylistTracks($playlist->id);
			$track_id_array = array();
			foreach ($playlistTracks->items as $track) {
			    $track = $track->track;
			    array_push($track_id_array,$track->id);
			}
			$value_count = array_count_values($track_id_array); // 各値の出現回数を数える
			$max = max($value_count); // 最大の出現回数を取得する
			if (0) {
				echo('<p>重複ありません</p>');
			} else {
				echo('<p>重複があります</p>');
				for($i=0;$i<$max;$i++){
					foreach($vaolue_count as $test){
					}
				}
			}
			$tracks = [
		    'tracks' => [
				['id' => '1Hk0QRlUFCHYG6zIvUh0Xd'],
			    ],
			];
			//$api->deletePlaylistTracks($delmyplay, $tracks,NULL);
		//addPlaylistTracks($delmyplay,$tracks);
			$tracks33 = $api->getTracks([  '1Hk0QRlUFCHYG6zIvUh0Xd']);

foreach ($tracks33->tracks as $tracks) {
    echo '<b>' . $track->name . '</b> by <b>' . $track->artists[0]->name . '</b> <br>';
}
		}
		 */
	}
	aaa("success");
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
