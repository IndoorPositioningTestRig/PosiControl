import React from "react";
import "./Setpoint.scss";
import DataPlotter from "../components/DataPlotter/DataPlotter";
import Dropdown from "../components/Dropdown/Dropdown";
import {BaseUrl} from "../constants/Api";
import Pid from "./Pid";

export default class extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      data: [],
      target: null,
      setPoint: "0",
      setPointWarning: false,
    };

    this.handleSetPointChange = this.handleSetPointChange.bind(this);
    this.handleConfirmClick = this.handleConfirmClick.bind(this);
  }

  handleValue(field, value) {
    this.setState({
      [field]: value,
    });
  }

  async handleConfirmClick() {
    const {target, setPoint, setPointWarning} = this.state;
    if (target === null || setPointWarning) {
      alert("Target and/or setPoint is invalid!");
      return;
    }

    const res = await fetch(
      `${BaseUrl}/setPoint/${target}/${Number.parseInt(setPoint)}/`, {
        method: "get"
      });
    const data = await res.text();
    this.setState({data: JSON.parse(data)});
  }

  handleSetPointChange(e) {
    const setPoint = e.target.value;
    const parsed = Number.parseInt(setPoint);
    let setPointWarning = isNaN(parsed);
    this.setState({setPoint, setPointWarning});
  }

  async fetchPid() {
    const res = await fetch(`${BaseUrl}/pid/${this.state.target}`, {
      method: "get",
    });
    const json = await res.json();
    return json;
  }

  render() {
    const {data, target, setPoint, setPointWarning} = this.state;

    return (
      <div className={"setpoint-screen"}>
        <div className={"left"}>
          <div className={"fields"}>
            {/* Target */}
            <div className={"field"}>
              <div className={"name"}>target:</div>
              <div className={"value"}>
                <Dropdown
                  onSelected={(value) => this.handleValue("target", value)}
                  value={target}
                  options={[0, 1, 2, 3, 4, 5, 6, 7, 8]}
                />
              </div>
            </div>
            {/* SetPoint */}
            <div className={"field"}>
              <div className={"name"}>setPoint:</div>
              <div className={"value"}>
                <input
                  className={`setpoint-input ${setPointWarning && "warning"}`}
                  type={"number"}
                  value={setPoint}
                  onChange={this.handleSetPointChange}
                />
              </div>
            </div>
          </div>
          {/* Confirm */}
          <div
            onClick={this.handleConfirmClick}
            className={"confirm-button"}
          >
          Send
          </div>
        </div>
        <div className={"right"}>
          <DataPlotter data={data}/>
        </div>
        <div>
          <Pid
            target={this.state.target}
          />
        </div>
      </div>
    );
  }
}
