
function myFunction() {
    var x, text;

    // Get the value of input field with id="pwd"

    x = document.getElementById("pwd").value;

    // If x is beiber, hehehehe you know dave's password

    if (x == "beiber") {
        text = "You know Dave's old password: bieberFever" ;
    } else {
        text = "You did not know Dave's old password was: bieberFever? Shame on you";
    }
    document.getElementById("demo").innerHTML = text;
}

function changeImage() {
    var image = document.getElementById("Ball");
    if (image.src.match("ball")) {
        image.src = "bat.png";
    } else {
	image.src = "ball.gif";
    }
}
