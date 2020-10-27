var socket = io();

// send out LedOn message over socket
function redLedON() {
    socket.emit('redLedON');
	console.log('redLedON');
}

function greenLedON() {
    socket.emit('greenLedON');
	console.log('greenLedON');
}

function blueLedON() {
    socket.emit('blueLedON');
	console.log('blueLedON');
}


// read the data from the message that the server sent and change the
// background of the webpage based on the data in the message
socket.on('server-msg', function(msg) {
    console.log('msg:', msg);
    switch(msg) {
        case 'pink':
            document.body.style.backgroundColor = 'pink';
            console.log('pink')
            break;
        case 'dark':
            document.body.style.backgroundColor = 'black';
            console.log('black');
            break;
    }
});
