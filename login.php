<?php
session_start();

if( isset($_SESSION["login"]) ) {
    header("Location: index.php");
    exit;
}

require 'database_connect.php';

if ( isset($_POST["login"]) ) {

    $username = $_POST["username"];
    $password = $_POST["password"];

    $result = mysqli_query($con, "SELECT * FROM user WHERE username = '$username'");

    //cek username
    if( mysqli_num_rows($result) === 1 ) {

        //cek password
        $row = mysqli_fetch_assoc($result);
        if( $row["password"] === $password ) {
            //set session
            $_SESSION["login"] = true;

            header("Location: index.php");
            exit;
        }

    }

    $error = true;

}

?>
<!DOCTYPE html>

<html>
<head>
<!-- Custom Style CSS -->
<link rel="stylesheet" href="custom.css">
    <title>Halaman Login</title>
    <style>
        label {
            display: block;
        }
    
    </style>
</head>

<body>

<h1 style="font-size:80px">Halaman Login</h1>



<form action="" method="post">

    <ul>
        <li>
            <label for="username" style="font-size:50px">Username :</label>
            <input type="text" name="username" id="username">
        </li>
        <li>
            <label for="password" style="font-size:50px">Password :</label>
            <input type="password" name="password" id="password">
        </li>
        <li>
            <button type="submit" name="login">Login</button>
        </li>
    </ul>
    
</form>

</body>
</html>