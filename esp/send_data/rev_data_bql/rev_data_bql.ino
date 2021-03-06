#include <ESP8266WiFi.h>
#include <SocketIOClient.h>
 
SocketIOClient client;
const char* ssid = "Tang 1";          //Tên mạng Wifi mà Socket server của bạn đang kết nối
const char* password = "sese0407";  //Pass mạng wifi ahihi, anh em rãnh thì share pass cho mình với.
 
char host[] = "52.90.24.18";  //Địa chỉ IP dịch vụ, hãy thay đổi nó theo địa chỉ IP Socket server của bạn.
int port = 2998;                  //Cổng dịch vụ socket server do chúng ta tạo!
 
//từ khóa extern: dùng để #include các biến toàn cục ở một số thư viện khác. Trong thư viện SocketIOClient có hai biến toàn cục
// mà chúng ta cần quan tâm đó là
// RID: Tên hàm (tên sự kiện
// Rfull: Danh sách biến (được đóng gói lại là chuối JSON)
extern String RID;
extern String Rfull;
 
 
//Một số biến dùng cho việc tạo một task
unsigned long previousMillis = 0;
long interval = 2000;
 
void setup()
{
    //Bật baudrate ở mức 115200 để giao tiếp với máy tính qua Serial
    Serial.begin(115200);
    delay(10);
     pinMode(LED_BUILTIN, OUTPUT);
     digitalWrite(LED_BUILTIN, HIGH); 
 pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
   
 
    //Việc đầu tiên cần làm là kết nối vào mạng Wifi
    Serial.print("Ket noi vao mang ");
    Serial.println(ssid);
 
    //Kết nối vào mạng Wifi
    WiFi.begin(ssid, password);
 
    //Chờ đến khi đã được kết nối
    while (WiFi.status() != WL_CONNECTED) { //Thoát ra khỏi vòng 
        delay(500);
        Serial.print('.');
    }
 
    Serial.println();
    Serial.println(F("Da ket noi WiFi"));
    Serial.println(F("Di chi IP cua ESP8266 (Socket Client ESP8266): "));
    Serial.println(WiFi.localIP());
 
    if (!client.connect(host, port)) {
        Serial.println(F("Ket noi den socket server that bai!"));
        return;
    }
 
    //Khi đã kết nối thành công
    if (client.connected()) {
        //Thì gửi sự kiện ("connection") đến Socket server ahihi.
        client.send("connection", "message", "Connected !!!!");
    }
}
 
void loop()
{
    //tạo một task cứ sau "interval" giây thì chạy lệnh:
   
 
    //Khi bắt được bất kỳ sự kiện nào thì chúng ta có hai tham số:
    //  +RID: Tên sự kiện
    //  +RFull: Danh sách tham số được nén thành chuỗi JSON!
    if (client.monitor()) {
        Serial.println(RID);
        Serial.println(Rfull);
        Serial.println(Rfull[1]);
        if(Rfull[1]=='o')
        {
             digitalWrite(LED_BUILTIN, LOW); 
            digitalWrite(5, HIGH);
        }  

        if(Rfull[1]=='f')
        {
             digitalWrite(LED_BUILTIN, HIGH); 
            digitalWrite(5, LOW);
        } 

    }
 
    //Kết nối lại!
    if (!client.connected()) {
      client.reconnect(host, port);
    }
}
