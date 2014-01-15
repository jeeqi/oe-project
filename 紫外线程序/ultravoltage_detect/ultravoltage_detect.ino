#include <UtraIndensity.h>


/* AnalogReadSerial
 Reads an analog input on pin 0, prints the result to the serial monitor
 This example code is in the public domain. */
UtraIndensity UtraIndensity(0);

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int nn;
  nn = UtraIndensity.UvNum();
  Serial.println(nn);
  delay(1000);
}
/*
紫外线指数	曝晒级数	含义	建议的防护措施
0–2	一级	最弱	属弱紫外线辐射天气，无需特别防护。若长期在户外，建议涂擦SPF在8-12之间的防晒护肤品
3–4	二级	弱	紫外线强度较弱，建议出门前涂擦SPF在12-15之间、PA+的防晒护肤品
5–6	三级	中等	属中等强度紫外线辐射天气，外出时建议涂擦SPF高于15、PA+的防晒护肤品，戴帽子、太阳镜.
7–9	四级	强	紫外线辐射强，建议涂擦SPF20左右、PA++的防晒护肤品。避免在10点至14点暴露于日光下.
10+	五级	很强	紫外线辐射极强，建议涂擦SPF20以上、PA++的防晒护肤品，尽量避免暴露于日光下.
*/
/*
紫外线指数	曝晒级数	晒伤时间(分钟)	建议的防护措施
0–2	低	－	－
3–5	中等	45	穿上长袖衣服，使用太阳帽及太阳眼镜
6–7	高	30	穿上长袖衣服，使用太阳帽及太阳眼镜
8–10	甚高	15	穿上长袖衣服，使用太阳帽及太阳眼镜，在上午十时至下午四时期间应避免在室外逗留.
11+	极高	10	穿上长袖衣服，使用太阳帽及太阳眼镜，在上午十时至下午四时期间应避免在室外逗留
*/
