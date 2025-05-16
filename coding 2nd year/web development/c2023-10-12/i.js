var num = 0, out = 0;
function getnum() {
    num = document.getElementById("num").value;
    out = Math.sqrt(num);
    document.getElementById("output").innerHTML = "The square root of number is: " + out;
}