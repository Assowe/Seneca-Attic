<html>
  <head>
    <title>FSOSS Registration</title>
  </head>
  <body>
  <?php
	$firstNameErr ="";
	$lastNameErr ="";
	$organizationErr ="";
	$emailErr ="";
	$phoneErr ="";
	$dataValid = true;
	// If submit with POST
	if ($_POST) { 
			// Test for nothing entered in field
		if ($_POST['firstName'] == "") {
			$firstNameErr = "Error - you must fill in a first name";
			$dataValid = false;
		}
		if ($_POST['lastName'] == "") {
			$lastNameErr = "Error - you must fill in a last name";
			$dataValid = false;		
		}
		if ($_POST['organization'] == "") {
			$organizationErr = "Error - you must fill in a organization";
			$dataValid = false;
		}
		if ($_POST['email'] == "") {
			$emailErr = "Error - you must fill in a email";
			$dataValid = false;		
		}
		if ($_POST['phone'] == "") {
			$phoneErr = "Error - you must fill in a phone";
			$dataValid = false;		
		}
		 
		 
	}
  if ($_POST && $dataValid) { 
         $firstName = $_POST['firstName'];
		 $lastName = $_POST['lastName'];
		 $organization = $_POST['organization'];
		 $email = $_POST['email'];
		 $phone = $_POST['phone'];
  }
  ?>
  <h1>FSOS Registration</h1>
  <form method="post" action="">
	<table>
	<tr>
    	<td valign="top">Title:</td>
	<td>
		<table>
		<tr>
		<td><input type="radio" name="title" value="mr">Mr</td>
		</tr>
		<tr>
		<td><input type="radio" name="title" value="mrs">Mrs</td>
		</tr>
		<tr>
		<td><input type="radio" name="title" value="ms">Ms</td>
		</tr>
		</table>
	</td>
	</tr>
	<tr>
    	<td>First name:</td>
	<td><input name="firstName" type="text" value="<?php if (isset($_POST['firstName'])) echo $_POST['firstName']; ?>"></td><td><?php echo $firstNameErr?></td>
	</tr>
	<tr>
    	<td>Last name:</td>
	<td><input name="lastName" type="text" value=""></td><td><?php echo $lastNameErr?></td>
	</tr>
	<tr>
    	<td>Organization:</td>
	<td><input name="organization" type="text" value=""></td><td><?php echo $organizationErr?></td>
	</tr>
	<tr>
    	<td>Email address:</td>
	<td><input name="email" type="text" value=""></td><td><?php echo $emailErr?></td>
	</tr>
	<tr>
    	<td>Phone number:</td>
	<td><input name="phone" type="text" value=""></td></td><td><?php echo $phoneErr?></td>
	</tr>
	<tr>
    	<td>Days attending:</td>
	<td>
		<input name="monday" type="checkbox" value="monday">Monday
		<input name="tuesday" type="checkbox" value="tuesday">Tuesday<td/>
	</tr>
	<tr>
	<td>T-shirt size:</td>
	<td>
	<select name="t-shirt">
	<option>--Please choose--</option>
	<option name="small" value="s">Small</option>
	<option value="m">Medium</option>
	<option value="l">Large</option>
	<option value="xl">X-Large</option>
	</select>
	</td>
	</tr>
	<tr><td><br></td></tr>
	<tr>
	<td></td>
	<td><input name="submit" type="submit"></td>
	</tr>
  </form>
  
  </body>
</html>