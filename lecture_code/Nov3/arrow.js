//console.log("Hello World!");
//document.write("<p>Javascript works!</p>");

// get canvas element from HTML document
var canvas = document.getElementById('myCanvas');

// get 2d context from canvas element
var context = canvas.getContext('2d');

function draw_arrow(x,y)
{
	// draw horizontal line
	context.beginPath();
	context.moveTo(x, y);
	context.lineTo(x-50, y);
	context.stroke();				

	// draw slanty line 1
	context.beginPath();
	context.moveTo(x-10, y-10);
	context.lineTo(x, y);
	context.stroke();				

	// draw slanty line 2
	context.beginPath();
	context.moveTo(x-10, y+10);
	context.lineTo(x, y);
	context.stroke();				
};

var tick = setInterval(update, 1000/30);
var i = 0;
function update(){
	context.clearRect (0,0,700,700 );
	draw_arrow( i++, 100 + Math.random()*10);
	if (i > 700) clearInterval(tick);
	
}
