<?php
    $json = json_decode(file_get_contents("php://input"), true);
    $database = mysqli_connect('localhost', 'payoff');
    if (mysqli_connect_errno()) {
        die("データベースに接続できません:" . mysqli_connect_error() . "\n");
            } else {
        echo "データベースの接続に成功しました。\n";
    }
    $payoff = mysqli_query($database,"SELECT * FROM payoff.test_info;");
    foreach($payoff as $row){
        echo $row;
    }
?>