import React from "react";
import PropTypes from "prop-types";
import "./Dropdown.scss";
import enhanceWithClickOutside from "react-click-outside"

class Dropdown extends React.Component{
  constructor(props) {
    super(props);

    this.state = {
      open: false,
    };

    this.handleSelected = this.handleSelected.bind(this);
    this.open = this.open.bind(this);
  }

  open() {
    this.setState({open: true});
  }

  handleSelected(selected) {
    this.props.onSelected(selected);
    this.setState({open: false});
  }

  handleClickOutside() {
    this.setState({open: false});
  }

  renderClosed() {
    const {value} = this.props;

    return (
      <div className={"wrapper closed"} onClick={this.open}>
        {value=== null ? "none" : value}
      </div>
    );
  }

  renderOpen() {
    const {options} = this.props;

    return (
      <div className={"wrapper open"}>
        <div
          className={"option"}
          key={"none"}
          onClick={() => this.handleSelected(null)}
        >
          none
        </div>
        {options.map((option) =>
          <div
            className={"option"}
            key={option}
            onClick={() => this.handleSelected(option)}
          >
            {option}
          </div>
        )}
      </div>
    );
  }

  render() {
    return (
      <div className={"dropdown"}>
        {this.state.open ?
          this.renderOpen() :
          this.renderClosed()
        }
      </div>
    );
  }
}

export default enhanceWithClickOutside(Dropdown);

Dropdown.propTypes = {
  options: PropTypes.array.isRequired,
  onSelected: PropTypes.func.isRequired,
  value: PropTypes.any,
};
