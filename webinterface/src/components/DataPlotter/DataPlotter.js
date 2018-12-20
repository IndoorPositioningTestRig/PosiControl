import React from "react";
import {LineChart} from "react-easy-chart";
import "./DataPlotter.scss";

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
  constructor(props) {
    super(props);

    this.state = {
      width: window.innerWidth,
    };

    this.handleResize = this.handleResize.bind(this);
  }

  handleResize() {
    this.setState({
      width: window.innerWidth,
    });
  }

  componentDidMount() {
    window.addEventListener("resize", this.handleResize);
  }

  componentWillUnmount() {
    window.removeEventListener("resize", this.handleResize);
  }

  render() {
    const {data} = this.props;
    const graphData = fromDatapoints(data || []);
    console.log("graphdata", graphData);
    let chartWidth = 600;
    if (this.state.width < 900) {
      chartWidth = this.state.width - 20;
    }

    return (
      <div className={"data-plotter"}>
        <div>
          <div className={"legend-item"}>
            <div style={{backgroundColor: "red"}} className={"legend-icon"}/>
            setpoint
          </div>
          <div className={"legend-item"}>
            <div style={{backgroundColor: "blue"}} className={"legend-icon"}/>
            output
          </div>
          <div className={"legend-item"}>
            <div style={{backgroundColor: "green"}} className={"legend-icon"}/>
              encoder
          </div>
        </div>
        <LineChart
          axes={true}
          margin={{top: 10, right: 10, bottom: 50, left: 50}}
          // margin={{top: 10, right: 10, bottom: 10, left: 10}}
          grid
          lineColors={["red", "blue", "green"]}
          verticalGrid
          width={chartWidth}
          height={400}

          // axisLabels={{x: "time in millis", y: "values"}}
          data={graphData}
        />
      </div>
    );
  }
}