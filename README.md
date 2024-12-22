# Patient Monitoring System  

A comprehensive **Patient Monitoring System** that enables real-time monitoring of vital signs and environmental conditions for both local and remote patients. The system leverages IoT technologies, integrating various sensors, microcontrollers, and protocols to ensure timely alerts and data-driven decision-making.  

## Features  
- **Vital Sign Monitoring**: Measures blood oxygen saturation (SpO2) and heart rate (BPM) using the **MAX30100 sensor**.  
- **Local Environment Monitoring**: Tracks temperature, humidity, and gas levels using:  
  - **DHT11** sensor for temperature and humidity.  
  - **MQ-2** sensor for gas detection.  
- **Remote Monitoring**: Employs a **Raspberry Pi** with additional sensors to monitor environmental conditions at a remote location.  
- **Alerts**: Buzzer triggers when vital or environmental readings exceed safe thresholds.  
- **Data Transmission**: Uses **NodeMCU** and the **MQTT protocol** for seamless communication between devices.  

## System Architecture  
The project consists of two main setups:  
1. **Local Monitoring**  
   - Components: Arduino, DHT11, MQ-2, MAX30100.  
   - Communication: NodeMCU with MQTT.  
   - Alerts: Buzzer for critical conditions.  

2. **Remote Monitoring**  
   - Components: Raspberry Pi, additional environmental sensors.  
   - Communication: MQTT for data transmission.  
   - Alerts: Buzzer for emergencies.  

## Technologies Used  
- **Microcontrollers**: Arduino, NodeMCU.  
- **Single-Board Computer**: Raspberry Pi.  
- **Sensors**: MAX30100, DHT11, MQ-2, additional gas sensors.  
- **Protocols**: MQTT for lightweight and reliable communication.  
- **Programming Languages**: C/C++, Python.  

## How It Works  
1. The **MAX30100 sensor** monitors SpO2 and BPM and sends the data to the NodeMCU.  
2. Environmental sensors (DHT11, MQ-2) gather data and transmit it to the monitoring system via MQTT.  
3. For remote monitoring, the Raspberry Pi subscribes to MQTT topics and processes incoming data.  
4. If abnormal readings are detected, a buzzer alerts the caretaker or healthcare provider.  

## Use Cases  
- **Hospitals**: Monitor multiple patients and environments.  
- **Home Care**: Track health parameters of individuals in remote areas.  
- **Elderly Care**: Real-time monitoring for proactive healthcare.  

## Installation and Setup  
1. Clone this repository:  
   ```bash
   git clone https://github.com/diptadeepray/remote_patient_monitoring_system.git
   cd patient_monitoring_system
