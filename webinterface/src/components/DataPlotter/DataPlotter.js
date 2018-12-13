import React from "react";
import {LineChart} from "react-easy-chart";

export function dummyData(len=12) {
  const data = [];
  for (let i = 0; i < len; i++) {
    data.push({
      setpoint: 0,
      output: (Math.random() * (255 * 2)) - 255,
      encoder: (Math.random() * 2000) - 1000,
      time: 100 * i,
    });
  }
  return data;
}

function fromDatapoints(datapoints) {
  const setpoints = [];
  const outputs = [];
  const encoders = [];

  datapoints.forEach((datapoint, index) => {
    setpoints.push({x: index * 100 , y:datapoint["setpoint"]/10});
    outputs.push({x: index * 100, y: datapoint["output"]/10});
    encoders.push({x: index * 100, y: datapoint["encoder"]/10});
  });

  return [setpoints, outputs, encoders];
}

export default class DataPlotter extends React.Component {
  render() {
    const {data} = this.props;
    const graphData = fromDatapoints(data || []);

    return (
      <div>
        <LineChart
          legend
          grid
          lineColors={["red", "blue", "green"]}
          verticalGrid
          width={600}
          height={400}
          margin={{top: 10, right: 30, bottom: 50, left: 70}}
          axisLabels={{x: "time in millis", y: "values"}}
          axes
          data={graphData}
        />
      </div>
    );
  }
}