var express = require("express");
var app = express();
app.use(express.static("public"));
app.set("view engine", "ejs");
app.set("views", "./views");

var server = require("http").Server(app);
var io = require("socket.io")(server);
server.listen(3000);

io.on("connection", function(socket){

  console.log("Co nguoi ket noi:" + socket.id);

  socket.on("atime",function(data)
  {
    console.log(data.message);

  })

  socket.on("disconnect", function(){
    console.log(socket.id + " ngat ket noi!!!!!");
  });

  setInterval(function(){
    socket.emit("ssc","oke");

  },3000)

});


app.get("/", function(req, res){
  res.render("trangchu");
});
