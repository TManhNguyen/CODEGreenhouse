import type { NextPage } from 'next'
import { Bar, BarChart, CartesianGrid, Cell, ComposedChart, Label, LabelList, Legend, Line, LineChart, Pie, PieChart, Tooltip, XAxis, YAxis } from 'recharts'
import BaseLayout from '../components/layout/BaseLayout'
import 'rc-slider/assets/index.css';
import LightingSlider from '../components/dashboard/sliders/LightingSlider';
import DliSlider from '../components/dashboard/sliders/DliSlider';
import MoistureSlider from '../components/dashboard/sliders/MoistureSlider';
import TempuratureSlider from '../components/dashboard/sliders/TemperatureSlider';
import LightToggle from '../components/dashboard/toggles/LightToggle';
import PumpToggle from '../components/dashboard/toggles/PumpToggle';
import FanToggle from '../components/dashboard/toggles/FanToggle';
import TemperatureStatCard from '../components/dashboard/cards/TemperatureStatCard';
import HumidityStatCard from '../components/dashboard/cards/HumidityStatCard';
import WaterLevelStatCard from '../components/dashboard/cards/WaterLevelStatCard';
import ExpenseStatCard from '../components/dashboard/cards/ExpenseStatCard';
import { CountUp } from 'use-count-up';
import { useEffect, useState } from 'react';
import useWebSocket, { ReadyState } from 'react-use-websocket';
import BubblerToggle from '../components/dashboard/toggles/BubblerToggle';
import TdsStatCard from '../components/dashboard/cards/TdsStatCard';
import PhStatCard from '../components/dashboard/cards/PhStatCard';
import LightLevelStatCard from '../components/dashboard/cards/LightStatCard';
import SolarStatCard from '../components/dashboard/cards/SolarStatCard';

const pieChartData = [
  { name: 'Lolo Salad ($3/kg)', value: 6 },
];

const COLORS = ['#f18179', '#82c5fb', '#83cab4'];

const RADIAN = Math.PI / 180;
const renderCustomizedLabel = ({ cx, cy, midAngle, innerRadius, outerRadius, percent, index }:any) => {
  const radius = innerRadius + (outerRadius - innerRadius) * 0.5;
  const x = cx + radius * Math.cos(-midAngle * RADIAN);
  const y = cy + radius * Math.sin(-midAngle * RADIAN);

  return (
    <>
    <text x={x} y={y} fill="white" textAnchor={x > cx ? 'start' : 'end'} dominantBaseline="central">
      {`${(percent * 100).toFixed(0)}%`}
    </text>
    </>
  );
};

const defaultSensorData = {
  temperature: 0,
  humidity: 0,
  waterLevel: 0,
  light: 0,
  tds: 0,
  ph: 0,
  solar: 0
}

const Home: NextPage = () => {
  const [sensorData, setSensorData] = useState(defaultSensorData)
  const [ledEnabled, setLedEnabled] = useState(false)
  const [pumpEnabled, setPumpEnabled] = useState(false)
  const [fanEnabled, setFanEnabled] = useState(false)

  // useEffect(() => {
  //   const data = {
  //     "command": "setLight",
  //     "device": "web",
  //     "value": ledEnabled ? 1 : 0
  //   }
  //   sendJsonMessage(data);
  // }, [ledEnabled])

  // useEffect(() => {
  //   const data = {
  //     "command": "setPump",
  //     "device": "web",
  //     "value": pumpEnabled ? 1 : 0
  //   }
  //   sendJsonMessage(data);
  // }, [pumpEnabled])

  // useEffect(() => {
  //   const data = {
  //     "command": "setFan",
  //     "device": "web",
  //     "value": fanEnabled ? 1 : 0
  //   }
  //   sendJsonMessage(data);
  // }, [fanEnabled])

  const sendCommand = (command:string, value:boolean) => {
    const data = {
      "command": command,
      "device": "web",
      "value": value ? 1 : 0
    }
    sendJsonMessage(data);
  }

  const {
    sendJsonMessage,
    lastJsonMessage,
    readyState
  } = useWebSocket("wss://c4s-iot-backend.herokuapp.com", {
    onOpen: () => {
      console.log("WS open...")
      const data = {
        "command": "setDevice",
        "device": "web"
      }
      sendJsonMessage(data);
    },
    onMessage: (webSocketMessage:any) => {
      const messageBody = JSON.parse(webSocketMessage.data)
      console.log(messageBody)
      switch (messageBody.command) {
        case "updateSensorData":
          setSensorData({
            ...sensorData, 
            temperature: messageBody.temperature < 100 ? messageBody.temperature : sensorData.temperature,
            humidity: messageBody.humidity < 100 ? messageBody.humidity : sensorData.humidity,
            waterLevel: messageBody.waterLevel < 100 ? messageBody.waterLevel : sensorData.waterLevel,
            light: messageBody.light,
            tds: messageBody.tds,
            ph: messageBody.ph,
            solar: messageBody.solar,
          })
          break;
      
        default:
          console.log("Unknown command: " + messageBody.command)
          break;
      }
      console.log("WS message...")
      console.log(messageBody)
    }
  });

  const connectionStatus = {
    [ReadyState.CONNECTING]: 'Connecting',
    [ReadyState.OPEN]: 'Connected',
    [ReadyState.CLOSING]: 'Closing',
    [ReadyState.CLOSED]: 'Closed',
    [ReadyState.UNINSTANTIATED]: 'Uninstantiated'
  }[readyState]

  return (
    <BaseLayout title="Home" socketStatus={connectionStatus}>
      <div className="max-w-7xl mx-auto gap-x-4 px-8 z-0 overflow-hidden lg:flex">
        <main className="flex-1 relative lg:my-8 z-0 overflow-y-auto focus:outline-none">
        <h2 className="text-3xl font-bold text-gray-900 mb-4">
          Showing statistics in <span className="text-blue-500">real-time</span>
          :
        </h2>      
          {/* Start main area*/}
          <div className="overflow-hidden mb-4">
            <dl className="grid grid-cols-1 md:grid-cols-3 gap-4">

              <TemperatureStatCard temperature={sensorData.temperature ?? 0} />
              <HumidityStatCard humidity={sensorData.humidity ?? 0} />
              <LightLevelStatCard light={sensorData.light ?? 0} />
              <SolarStatCard solar={sensorData.solar ?? 0} />

              <TdsStatCard tds={sensorData.tds ?? 0} />
              <PhStatCard ph={sensorData.ph ?? 0} />
              <WaterLevelStatCard waterLevel={sensorData.waterLevel ?? 0} />

              <div className="md:col-span-2 gap-y-2 p-4 w-full rounded bg-white">
                <div className="flex flex-row">
                  <div className="flex-auto flex flex-col gap-y-2">
                    <dt className="font-medium text-gray-500">Revenue</dt>
                    {/* <dt className="order-2 text-base font-medium text-gray-500">Delivery</dt> */}
                    <dd className="text-5xl font-bold text-green-600">
                    <CountUp isCounting end={6} duration={0.5} /> 
                      <span className="text-xl ml-2 text-green-500">USD</span>
                    </dd>
                    <dt className="font-medium text-gray-500">
                      Estimated revenue
                    </dt>
                  </div>
                  <div className="flex-shrink">
                  <PieChart width={320} height={150}>
                    <Pie
                      data={pieChartData}
                      cx="50%"
                      cy="50%"
                      labelLine={false}
                      label={renderCustomizedLabel}
                      outerRadius={70}
                      fill="#8884d8"
                      dataKey="value"
                    >

                      {pieChartData.map((entry, index) => (
                        <Cell key={`cell-${index}`} fill={COLORS[index % COLORS.length]} />
                        ))}
                    </Pie>
                    <Tooltip />
                    <Legend iconSize={10} layout="vertical" verticalAlign="middle" align="right" />
                  </PieChart>
                  </div>
                </div>
              </div>

              <div className="flex flex-col gap-y-2 p-4 w-full rounded bg-white">
                <dt className="font-medium text-gray-500">Price</dt>
                <dd>
                  <ul className="font-medium text-gray-900 mb-4">
                    <li><span className="text-red-400">Electricity:</span> $0.1/kWh</li>
                    <li><span className="text-blue-400">Water:</span> $0.5/Cub m</li>
                  </ul>
                </dd>
              </div>


            </dl>
          </div>
          
        </main>
        <aside className="relative mb-8 lg:my-8 lg:flex lg:flex-col flex-shrink-0 gap-y-4 w-full lg:w-96">
          {/* Start secondary column (hidden on smaller screens) */}
          <div className="bg-white p-4 rounded">
            <div className="flex flex-col mb-4">
              <div className="font-medium text-xl">
                Controls
              </div>
              <div className="text-base font-medium text-gray-500">
                You can control the device yourself using the following buttons.  
              </div>
            </div>
            <div className="grid grid-cols-1 md:grid-cols-3 gap-4">
              <LightToggle enabled={ledEnabled} onClick={
                () => {sendCommand("setLight", !ledEnabled); setLedEnabled(!ledEnabled);}} />
              <PumpToggle enabled={pumpEnabled} onClick={
                () => {sendCommand("setPump", !pumpEnabled); setPumpEnabled(!pumpEnabled);}} />
              <FanToggle enabled={fanEnabled} onClick={
                () => {sendCommand("setFan", !fanEnabled); setFanEnabled(!fanEnabled);}} />
              
            </div>
          </div>

          
          {/* <div className="bg-white p-4 rounded">
            <div className="flex flex-col mb-4">
              <div className="flex-shrink-0 font-medium text-xl">
                Automation
              </div>
              <div className="text-base font-medium text-gray-500">
                The system will auto-adjust to meet the following environment configurations.  
              </div>
            </div>

            <div className="flex flex-col gap-y-4 mb-4">
              <LightingSlider />
              <DliSlider />
              <MoistureSlider />
              <TempuratureSlider />
            </div>
          </div> */}


          {/* End secondary column */}
        </aside>
      </div>
    </BaseLayout>
  )
}

export default Home
