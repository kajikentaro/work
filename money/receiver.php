<?php
    $json = json_decode(file_get_contents("php://input"), true);
    $database = mysqli_connect('localhost', 'payoff');
    $res = mysqli_query($database,'INSERT INTO payoff.money VALUES ("'.$json['des'].'",'.$json['yen'].')');
    echo $res;
?>