import time
import random
import paho.mqtt.client as mqtt

client = mqtt.Client("Publisher")
client.connect("localhost", 1883)

for i in range(10):
    data = {
        "altitude": random.randint(0, 1000),
        "speed": random.randint(0, 500),
        "temperature": random.randint(-20, 50)
    }
    client.publish("rocket/telemetry", str(data))
    print(f"Published: {data}")
    time.sleep(1)

