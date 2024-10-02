#define rightMotorForward 18
#define rightMotorReverse 19
#define leftMotorForward 4
#define leftMotorReverse 5
#include <WiFi.h>
#include <WiFiUdp.h>
WiFiUDP UDPTestServer;

int startNote[160] = {29090900,29697000,30597000,32097000,32997000,33597000,34497000,35397000,36897000,37797000,38397000,39297000,40197000,41697000,42597000,43197000,44097000,44997000,46497000,47397000,47997000,48897000,49797000,51297000,52197000,52797000,53697000,54597000,56097000,56997000,57597000,58497000,59397000,60897000,61797000,62397000,63297000,64197000,65697000,66597000,67197000,67497000,68097000,68997000,70497000,71397000,71997000,72897000,73797000,75297000,76197000,76797000,77697000,78597000,80097000,80997000,81597000,82497000,83397000,84897000,85797000,87297000,88206100,89721200,90630300,91236400,92145500,93054600,94569700,95478800,96084900,96994000,97903100,99418200,100327300,100933400,101842500,102751500,104266700,105175800,105781800,106690900,107600000,109115200,110024300,110630300,111539400,112448500,113963700,114872800,115478800,116387900,117297000,118812200,119721300,120327300,121236400,122145500,123660600,124569700,125175800,126084900,143054600,144872800,145478800,146387900,147903100,148812200,149418200,150327300,151236400,152751600,153660700,154266700,155175800,156084900,157600100,158509200,159115200,160024300,160933400,162448600,163357600,163963700,164872800,165781900,167297000,168206100,168812200,169721300,170630400,172145500,173054600,173660700,174569800,175478900,176994000,177903100,178509200,179418300,180327400,181842500,182751600,183357700,184266700,185175800,186691000,187600100,188206100,189115200,190024300,191539500,192448600,193054600,193963700,194872800,196388000,197297100,197903100,198812200};
int duration[159];

int checkUDP() {
  char packetBuffer[100];
  int cb = UDPTestServer.parsePacket();
  if (cb) {
    int len = UDPTestServer.read(packetBuffer, 100);
    packetBuffer[len] = 0;
    if (packetBuffer[0] == 'T') return 1;
    if (packetBuffer[0] == 'G') return 2;
  }
  return 0;
}

void forward(int motorpin, int power, int Time) {
  analogWrite(motorpin, power);
  delay(Time);
  analogWrite(motorpin, 0);
}

void setup() {
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorReverse, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorReverse, OUTPUT);
  Serial.begin(115200);
  WiFi.begin("TP-Link_05AF", "47543454");
  WiFi.config(IPAddress(192, 168, 1, 59), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connected");
  }
  UDPTestServer.begin(2808);

  for (int i = 0; i < 159; i++){
    duration[i] = startNote[i+1]-startNote[i];
  }
}

void loop() {
  int msg = checkUDP();
  if (msg == 2 ) {
    Serial.println("Play");
    delayMicroseconds(startNote[0]);
    for (int i = 0; i < 160; i++) {
      if (i % 2) {
        forward(rightMotorForward, 255, 80);
        delayMicroseconds(duration[i] - 80000);
      } else {
        forward(leftMotorForward, 255, 70);
        delayMicroseconds(duration[i] - 70000);
      }
     }
   }
   else if (msg == 1){
    Serial.println("Test");
    delay(900);
    forward(rightMotorForward, 255, 100);
   }
}
