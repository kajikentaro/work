<?php
require 'vendor/autoload.php';

$session = new SpotifyWebAPI\Session(
    '511d24499f014e2b8eb0b8b7e0fbb04f',
    '4dd24eb2caa34090b736f827785e2dd0',
    'https://google.com'
);

// Request a access token using the code from Spotify
$session->requestAccessToken($_GET['code']);

$accessToken = $session->getAccessToken();
$refreshToken = $session->getRefreshToken();

// Store the access and refresh tokens somewhere. In a database for example.

// Send the user along and fetch some data!
header('Location: app.php');
die();
?>
