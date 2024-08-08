use iced::{Element, Task};

mod ui;

fn main() -> iced::Result {
    iced::application(
        "PAT Report Generator",
        PatGenerator::update,
        PatGenerator::view,
    )
    .run()
}

#[derive(Debug, Clone)]
enum Message {
    Pages(ui::UiEvent),    
}

struct PatGenerator {
    pages: ui::Pages,
}

impl PatGenerator {
    fn update(&mut self, message: Message) -> Task<Message> {
        match message {
            Message::Pages(x) => self.pages.update(x).map(Message::Pages),
        }
    }

    fn view(&self) -> Element<Message> {
        self.pages.view().map(Message::Pages)
    }
}

impl Default for PatGenerator {
    fn default() -> Self {
        Self {
            pages: ui::Pages::new(),
        }
    }
}
