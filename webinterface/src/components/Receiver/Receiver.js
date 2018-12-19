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
        this.setState({data: data});
      })
    });
  }

  render() {
    return (
      <div>
        <button onClick={this.handleClick}>Click me</button>
        <DataPlotter data={this.state.data}/>
      </div>
    );
  }
}
