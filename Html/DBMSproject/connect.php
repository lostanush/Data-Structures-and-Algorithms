<?php
    echo "HelloSFSDFSDFSDF<br>\n";
    echo "Date is : " . date("j-m-y, h:i:s");
    echo "<br>\n";
    
   // Connect to PostgreSQL
    $conn = new PDO("pgsql:host=localhost;dbname=mydatabase", "username", "password");

    // Prepare and execute SQL query
    $stmt = $conn->prepare("SELECT * FROM mytable");
    $stmt->execute();

    // Fetch all rows as associative array
    $rows = $stmt->fetchAll(PDO::FETCH_ASSOC);

    // Output data as JSON
    echo json_encode($rows);

    $name = $_POST['name'];
    $password = $_POST['password'];

// Now you can use $name and $password variables to process the form data

    $name = filter_input(INPUT_POST, "name", FILTER_SANITIZE_STRING);
    $password = filter_input(INPUT_POST, "password", FILTER_SANITIZE_STRING);

    if (!empty($name) && !empty($password)) {
        $host = "localhost";
        $dbname = "project01";
        $username = "your_username";
        $password_db = "your_password";

        try {
            $conn = new PDO("pgsql:host=$host;dbname=$dbname", $username, $password_db);
            $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            $stmt = $conn->prepare("INSERT INTO account (username, password) VALUES (:username, :password)");
            $stmt->bindParam(':username', $name);
            $stmt->bindParam(':password', $password);

            $stmt->execute();
            echo "New record inserted successfully";
        } catch(PDOException $e) {
            echo "Connection failed: " . $e->getMessage();
        }
        $conn = null;
    } else {
        echo "Error: Name and password cannot be empty";
    }
?>
