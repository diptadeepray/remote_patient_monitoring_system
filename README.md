# Patient Monitoring and Alert System 

## Motivation of the Project
In the rapidly evolving field of healthcare, the integration of technology has become imperative to improve patient outcomes, enhance the efficiency of medical services, and reduce healthcare costs. The primary objective of this **Patient Monitoring System** is to ensure the timely and accurate collection of critical physiological data, such as heart rate, blood oxygen levels, and body temperature for both local and remote patients. 

This data is crucial for the early detection of potential health issues, allowing for prompt intervention and thereby improving patient prognosis. Traditional methods of monitoring, which often rely on periodic manual checks, are prone to delays and inaccuracies. In contrast, an IoT-based monitoring system can provide continuous, real-time data, significantly enhancing the quality of patient care.

## Features  
- **Vital Sign Monitoring**:  
  - Measures **SpO2** (blood oxygen saturation level) and **BPM** (heart rate) using the **MAX30100 sensor**.  
  - Alerts triggered if SpO2 or BPM values fall outside safe thresholds.  
- **Environmental Monitoring**:  
  - Tracks room **temperature**, **humidity**, and **smoke levels** using **DHT11** and **MQ-135 sensors**.  
  - Alerts activated for abnormal temperature, humidity, or smoke levels.  
- **Data Communication**:  
  - Uses **I2C protocol** for local sensor communication.  
  - Transmits data over the internet using **ESP8266 NodeMCU** and the **MQTT protocol**.  
- **Display and Alert for Medical Staff**:  
  - Displays SpO2 and BPM readings on a **16x2 LCD**.  
  - Activates a buzzer if readings are outside safe thresholds. 

## System Architecture  
The system consists of three interconnected components:

### 1. **Patient-Side NodeMCU**  
- **Inputs**:  
  - MAX30100 sensor for SpO2 and BPM.  
  - DHT11 sensor for temperature and humidity.  
  - MQ-135 sensor for smoke detection.  
- **Outputs**:  
  - Activates a buzzer for abnormal SpO2, BPM, temperature, humidity, or smoke levels.  
- **Communication**:  
  - Transmits SpO2 and BPM readings to the doctor-side NodeMCU via MQTT. 

### 2. **Doctor-Side NodeMCU**  
- **Inputs**:  
  - Receives SpO2 and BPM readings via MQTT.  
- **Outputs**:  
  - Displays readings on a **16x2 LCD**.  
  - Activates a buzzer if SpO2 or BPM values are outside safe thresholds.  

### 3. **Environmental Monitoring with Arduino**  
- **Inputs**:  
  - DHT11 sensor for temperature and humidity.  
  - MQ-135 sensor for smoke detection.  
- **Outputs**:  
  - Activates a buzzer for abnormal environmental readings.

## Technologies Used  
- **Microcontrollers**: ESP8266 NodeMCU, Arduino.  
- **Sensors**:  
  - **MAX30100**: Measures SpO2 and BPM.  
  - **DHT11**: Measures temperature and humidity.  
  - **MQ-135**: Detects smoke levels.  
- **Protocols**:  
  - **I2C**: Local sensor communication.  
  - **MQTT**: Data transmission between NodeMCU modules.  
- **Display**: 16x2 LCD.  
- **Programming Languages**: C/C++, Arduino IDE.  

## How It Works  
1. **Vital Monitoring**:  
   - The **MAX30100 sensor** is connected to the patient-side NodeMCU that measures SpO2 and BPM.
   - The NodeMCU continuously sends the data to the doctor-side NodeMCU over MQTT.  
   - If readings are abnormal, the NodeMCU activates a buzzer.
2. **Doctor-Side Monitoring**:  
   - The doctor-side NodeMCU receives the readings, displays them on a **16x2 LCD**.
   - The NodeMCU also activates a buzzer for abnormal readings.  
3. **Environmental Monitoring**:  
   - The **DHT11** and **MQ-135 sensors** connected to the Arduino measure room temperature, humidity, and smoke levels.  
   - If environmental conditions are unsuitable, the Arduino triggers another buzzer to alert people around the patient.   

## Use Cases  
- **Hospitals**: Monitor patients' vitals and room conditions remotely and locally.  
- **Home Care**: Ensure patient safety in local and remote environments.  
- **Emergency Alerts**: Enable timely intervention by medical staff in case of emergency.  

## Installation and Setup  
1. Clone this repository:  
   ```bash
   git clone https://github.com/diptadeepray/remote_patient_monitoring_system.git
   cd patient_monitoring_system
