use iced::{widget::{button, column, container, horizontal_space, row, text, text_input}, Alignment, Element, Length, Task};

pub struct State {
    customer_name: String,
    comapny_name: String,
    address: String,
    postcode: String,
    phone_number: String,
    email: String,
    date: String,
}

#[derive(Debug, Clone)]
pub enum Event {
    Submit,

    CustomerNameInput(String),
    CompanyNameInput(String),
    AddressInput(String),
    PostcodeInput(String),
    PhoneNumberInput(String),
    EmailInput(String),
    DateInput(String),
}

impl State {
    pub fn new() -> Self {
        State {
            customer_name: String::new(),
            comapny_name: String::new(),
            address: String::new(),
            postcode: String::new(),
            phone_number: String::new(),
            email: String::new(),
            date: String::new(),
        }
    }

    pub fn update(&mut self, message: Event) -> Task<Event> {
        match message {
            Event::Submit => return Task::none(),
            Event::CustomerNameInput(name) => {
                self.customer_name = name;
            }
            Event::CompanyNameInput(name) => {
                self.comapny_name = name;
            }
            Event::AddressInput(address) => {
                self.address = address;
            }
            Event::PostcodeInput(postcode) => {
                self.postcode = postcode;
            }
            Event::PhoneNumberInput(phone_number) => {
                self.phone_number = phone_number;
            }
            Event::EmailInput(email) => {
                self.email = email;
            }
            Event::DateInput(date) => {
                self.date = date;
            }
        }
        
        Task::none()
    }

    pub fn view(&self) -> Element<Event> {
        container(column![
            text("Report Information").size(30),
            row![
                text("Customer name:"),
                horizontal_space(),
                text_input("...", &self.customer_name).on_input(Event::CustomerNameInput).width(700)
            ].align_y(Alignment::Center).padding(20).spacing(20),
            row![
                text("Company name:"),
                horizontal_space(),
                text_input("...", &self.comapny_name).on_input(Event::CompanyNameInput).width(700)
            ].align_y(Alignment::Center).padding(20).spacing(20),
            row![
                text("Address:"),
                horizontal_space(),
                text_input("...", &self.address).on_input(Event::AddressInput).width(700)
            ].align_y(Alignment::Center).padding(20).spacing(20),
            row![
                text("Postcode:"),
                horizontal_space(),
                text_input("...", &self.postcode).on_input(Event::PostcodeInput).width(700)
            ].align_y(Alignment::Center).padding(20).spacing(20),
            row![
                text("Phone number:"),
                horizontal_space(),
                text_input("...", &self.phone_number).on_input(Event::PhoneNumberInput).width(700)
            ].align_y(Alignment::Center).padding(20).spacing(20),
            row![
                text("Email:"),
                horizontal_space(),
                text_input("...", &self.email).on_input(Event::EmailInput).width(700)
            ].align_y(Alignment::Center).padding(20).spacing(20),
            row![
                text("Date:"),
                horizontal_space(),
                text_input("...", &self.date).on_input(Event::DateInput).width(700)
            ].align_y(Alignment::Center).padding(20).spacing(20),
            button("Create report").on_press(Event::Submit).width(Length::Fill)

        ])
        .into()
    }
}