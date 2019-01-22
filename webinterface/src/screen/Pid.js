import React from "react";
import "./Pid.scss";
import {getBaseUrl} from "../constants/Api";
import PropTypes from "prop-types";

const values = ["p", "i", "d"];

export default class Pid extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      p: 0,
      i: 0,
      d: 0,
      errors: {}
    };

    this.handleChange = this.handleChange.bind(this);
    this.handleConfirmClick = this.handleConfirmClick.bind(this);
  }

  handleChange(field, value) {
    this.setState({
      [field]: value,
    });
  }

  handleConfirmClick() {
    if (this.props.target === null) {
      alert("No target selected!");
      return;
    }

    let PID = this.state;
    const {errors} = this.state;
    let hasError = false;

    values.forEach((value) => {
      const numVal = Number.parseFloat(PID[value]);
      errors[value] = Number.isNaN(numVal);
      hasError = hasError || errors[value];
      PID[value] = numVal;
    });

    if (hasError) {
      this.setState({errors});
      alert("Only floating point values are allowed for PID");
      return;
    }

    return fetch(`${getBaseUrl()}/set_pid/${this.props.target}/${PID["p"]}/${PID["i"]}/${PID["d"]}/`, {
      method: "post",
    });
  }

  render() {
    return (
      <div className={"pid-screen"}>
        <b>PID</b>
        <div className={"pid-input"}>
          <div className={"field"}>
            <div className={"name"}>P</div>
            <input
              type={"number"}
              value={this.state.p}
              onChange={(e) => this.handleChange("p", e.target.value)}
            />
          </div>
          <div className={"field"}>
            <div className={"name"}>I</div>
            <input
              type={"number"}
              value={this.state.i}
              onChange={(e) => this.handleChange("i", e.target.value)}

            />
          </div>
          <div className={"field"}>
            <div className={"name"}>D</div>
            <input
              type={"number"}
              value={this.state.d}
              onChange={(e) => this.handleChange("d", e.target.value)}
            />
          </div>
        </div>
        <div
          onClick={this.handleConfirmClick}
          className={"confirm-button"}
        >
          Apply
        </div>
      </div>
    );
  }
}

Pid.propTypes = {
  target: PropTypes.number,
};
