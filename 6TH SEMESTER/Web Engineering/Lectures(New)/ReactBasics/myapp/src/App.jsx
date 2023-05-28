import { Component } from "react";
import React, { useState } from "react";
import "./App.css";
import Game from "./Game";

class App extends Component {
  constructor(props) {
    super(props);
    this.state = { value: "" };
    this.handleChange = this.handleChange.bind(this);
    this.handleSubmit = this.handleSubmit.bind(this);
  }

  handleChange = (event) => {
    this.setState({ value: event.target.value });
  };

  handleSubmit = (event) => {
    event.preventDefault();
    alert("A name was submitted: " + this.state.value);
  };

  render() {
    const { value } = this.state;
    const name = value;

    return (
      // <div>
      //   <Game />
      </div>
      <div>
        <form onSubmit={this.handleChange}>
          <h1>Controlled From Example</h1>
          <label htmlFor="name">Name: </label>
          <input
            type="text"
            name="name"
            id=""
            value={this.state.value}
            onChange={this.handleChange}
          />
          <input type="submit" value="Submit" onClick={this.handleSubmit} />
        </form>
        <div>{name && <p> Welcome {name}</p>}</div>
      </div>
    );
  }
}

export default App;
