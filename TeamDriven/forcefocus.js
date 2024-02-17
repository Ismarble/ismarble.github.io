<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Force Focus into Text Box</title>
</head>
<body>

<input type="text" id="myTextBox" placeholder="Type something here">

<script>
window.onload = function() {
    document.getElementById('myTextBox').focus();
};
</script>

</body>
</html>