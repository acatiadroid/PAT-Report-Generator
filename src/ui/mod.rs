use iced::{Element, Task};

mod new_report;
mod start;

pub struct Pages {
    current_page: Page,

    new_report: new_report::State,
    start: start::State,
}

#[derive(Debug, Clone)]
pub enum UiEvent {
    Start(start::Event),
    NewReport(new_report::Event),
}

enum Page {
    Start,
    NewReport,
    ReportHistory,
    EditReport,
}

impl Pages {
    pub fn new() -> Self {
        Pages {
            current_page: Page::Start,

            new_report: new_report::State::new(),
            start: start::State::new(),
        }
    }

    pub fn update(&mut self, message: UiEvent) -> Task<UiEvent> {
        match message {
            UiEvent::Start(event) => {
                self.start.update(event).map(UiEvent::Start)
            }
            UiEvent::NewReport(event) => {
                self.new_report.update(event).map(UiEvent::NewReport)
            }
        }
    }

    pub fn view(&self) -> Element<UiEvent> {
        match &self.current_page {
            Page::Start => self.start.view().map(UiEvent::Start),
            Page::NewReport => self.new_report.view().map(UiEvent::NewReport),
            Page::ReportHistory => todo!(),
            Page::EditReport => todo!(),
        }
    }


}