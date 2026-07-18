# Shopping Cart CLI System (Ruby)

![ruby](https://img.shields.io/badge/ruby-3.x-red)
![license](https://img.shields.io/badge/License-MIT-blue.svg)

A modular, object-oriented Shopping Cart System built with Ruby. This project demonstrates core OOP principles, state-based inventory management, and persistent data storage using JSON files, providing a reliable foundation for e-commerce logic.

## 🌟 Key Features

* **Persistent Data Storage:** Customer and product data are seamlessly saved to and loaded from `customers.json` and `product.json`, ensuring data integrity across sessions.
* **Stateful Inventory Control:** Implements a status-based mechanism for products, preventing duplicate purchases and ensuring accurate stock availability.
* **Dynamic Coupon System:** Supports coupon code validation (e.g., "SAVE10") for automated real-time price calculations and discount application.
* **Automated Test Suite:** Built with Minitest to rigorously verify business logic, including customer registration, cart operations, and the checkout process.
* **Interactive CLI:** A robust command-line interface designed to handle user authentication, inventory browsing, and order finalization.

## 🏗️ Architecture & Core Principles

The project is structured to prioritize clean code and separation of concerns:

* **Object-Oriented Design:** Entities are encapsulated into dedicated classes (`Customer`, `Product`, `ShoppingCart`), ensuring maintainable and scalable code.
* **Custom Serialization:** Utilizes custom `to_h` methods to transform objects into JSON-compatible hashes for efficient storage and retrieval.
* **Data Integrity:** Employs strict validation checks on product states and ID consistency to prevent system errors during runtime.
* **Workflow Automation:** Business logic is isolated from the UI, allowing for independent testing and modular updates.

## ⚠️ Operation Logic Flow

The system follows a validation-first approach to manage user requests:

```text
[User Request]
       |
       v
[Validate ID & State]
       |
  /----+----\
  |         |
(Error)   (Success)
  |         |
[Prompt]  [Update Data & Save JSON]