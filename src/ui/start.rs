use iced::{widget::{button, column, container, text}, Alignment, Element, Length, Task};

pub struct State {}

#[derive(Debug, Clone)]
pub enum Event {
    OpenNewReportPage,
    OpenReportHistoryPage,
}

impl State {
    pub fn new() -> Self {
        State {}
    }

    pub fn update(&mut self, message: Event) -> Task<Event> {
        match message {
            Event::OpenNewReportPage => {
                // Open new report page
            }
            Event::OpenReportHistoryPage => {
                // Open report history page
            }
        }
        
        Task::none()
    }

    pub fn view(&self) -> Element<Event> {
        container(
            column![
                text("PAT Report Generator").size(30),
                button("Create new report").on_press(Event::OpenNewReportPage),
                button("See report history").on_press(Event::OpenReportHistoryPage),
            ]
            .spacing(15)
            .align_x(Alignment::Center),
        )
        .center(Length::Fill)
        .into()
    }
}