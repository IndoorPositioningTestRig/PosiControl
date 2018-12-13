import React from "react";
import "./Receiver.scss";
import {BaseUrl} from "../../constants/Api";
import DataPlotter, {dummyData} from "../DataPlotter/DataPlotter";


export default class Receiver extends React.Component{
  constructor(props) {
    super(props);

    this.state = {
      data: [],
    };

    this.handleClick = this.handleClick.bind(this);
  }

  handleClick() {
    if (this.props.target === null || this.props.target === undefined) {
      alert("target is not set!");
      return;
    }

    // this.setState({data: dummyData(50)});

    fetch(`${BaseUrl}/debug/${this.props.target}/`, {
      method: "get",
    }).then((response) => {
      response.json().then(data => {
        console.log('response', data);
        this.setState({data: data});
      })
    });
  }

  render() {
    console.log(this.props);

    return (
      <div>
        <button onClick={this.handleClick}>Click me</button>
        <div>
          red: setpoint
        </div>
        <div>
          blue: output
        </div>
        <div>
          green: encoder
        </div>
        <DataPlotter data={this.state.data}/>
      </div>
    );
  }
}
