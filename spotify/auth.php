<?php
require 'vendor/autoload.php';

$session = new SpotifyWebAPI\Session(
    '511d24499f014e2b8eb0b8b7e0fbb04f',
    '4dd24eb2caa34090b736f827785e2dd0',
    'http://localhost/spotify/app.php/'
);

$options = [
    'scope' => [
        'playlist-read-private',
        'user-read-private',
    ],
];

header('Location: ' . $session->getAuthorizeUrl($options));
die();
?>
