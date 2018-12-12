import React from 'react';
import "./Receiver.scss";
import {BaseUrl} from "../../constants/Api";


export default class Receiver extends React.Component{
  constructor(props) {
    super(props);

    this.state = {
      data: "",
    }

    this.handleClick = this.handleClick.bind(this);
  }

  handleClick() {
    if (this.props.target === null || this.props.target === undefined) {
      alert("target is not set!");
      return;
    }

    fetch(`${BaseUrl}/debug/${this.props.target}/`, {
      method: "get",
      mode: "no-cors",
    }).then((response) => {
        console.log(response);
        response.json().then(data => {
          this.setState({data});
        });
    });
  }

  render() {
    return (
      <div>
        <button onClick={this.handleClick}>Click me</button>
        <textarea value={this.state.data}></textarea>
      </div>
    )
  }
}