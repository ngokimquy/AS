var express = require("express");
var app = express();
app.use(express.static("public"));
app.set("view engine", "ejs");
app.set("views", "./views");

var server = require("http").Server(app);
var io = require("socket.io")(server);
server.listen(2998);

io.on("connection", function(socket){

  console.log("Co nguoi ket noi:" + socket.id);

  socket.on("csends",function(data)
  {
    console.log(data);

  })

  socket.on("khancap",function(data)
  {
    console.log(data.message);
    if(data.message=='1')
    {
      console.log("tin hieu khan cap");
      io.sockets.emit("ssc","on1");
      
    }
    if(data.message=='2')
    {
      console.log("tin hieu khan cap");
      io.sockets.emit("ssc","on2");
      
    }

  })

  socket.on("tatchuong",function(data)
  {
    console.log(data);
    io.sockets.emit("tatchuong",data);

  })
  socket.on("disconnect", function(){
    console.log(socket.id + " ngat ket noi!!!!!");
  });
/*
  setInterval(function(){
    socket.emit("ssc","oke");

  },3000)

 */ 

});


app.get("/", function(req, res){
  res.render("trangchu");
});
