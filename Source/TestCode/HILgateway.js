const SerialPort = require('./serialport')
const Readline = require('./@serialport/parser-readline')
 
// list serial ports:

/*
serialport.list(function (err, ports) {
  ports.forEach(function(port) {
    console.log(port.comName);
  });
});
*/

const myPort = new SerialPort(process.argv[2], {
   baudRate: 9600,
   // look for return and newline at the end of each data packet:
 });
 
const parser = myPort.pipe(new Readline({ delimiter: '\r\n' }))
 
parser.on('open', showPortOpen);
parser.on('data', sendSerialData);
parser.on('close', showPortClose);
parser.on('error', showError); 

function showPortOpen() {
   console.log('port open. Data rate: ' + myPort.options.baudRate);
}
 
function sendSerialData(data) {
   console.log(data);
   if(data.indexOf("Success") > -1) {
		console.log("OK: HIL Test Passed");
		process.exit();
}
}
 
function showPortClose() {
   console.log('port closed.');
   process.exit(1);
}
 
function showError(error) {
   console.log('Serial port error: ' + error);
   process.exit(1);
}

setTimeout(function(str1, str2) {
  console.log(str1 + " " + str2);
  process.exit(1);
}, 20000, "Timeout:", "Test System do not respond");

setTimeout(function(str1) {
  console.log(str1);
  myPort.write("SetParameters " + process.argv[3] + " " + process.argv[4] + " " + process.argv[5] + "\n");
  myPort.write("Start\n");
}, 2000, "Test Start");

