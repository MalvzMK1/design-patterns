from abc import ABC, abstractmethod


class Report:
    def __init__(self) -> None:
        self.sections = []

    def add(self, content: str) -> None:
        self.sections.append(content)

    def render(self) -> str:
        return "\n".join(self.sections)


class ReportBuilder(ABC):
    @abstractmethod
    def reset(self) -> None:
      pass

    @abstractmethod
    def add_title(self, text: str) -> None:
      pass

    @abstractmethod
    def add_summary(self, text: str) -> None:
      pass

    @abstractmethod
    def add_charts(self) -> None:
      pass

    @abstractmethod
    def get_result(self) -> Report:
      pass


class PlainTextReportBuilder(ReportBuilder):
    def __init__(self) -> None:
        self.reset()

    def reset(self) -> None:
        self._report = Report()

    def add_title(self, text: str) -> None:
        self._report.add(f"# {text}")

    def add_summary(self, text: str) -> None:
        self._report.add(f"Summary: {text}")

    def add_charts(self) -> None:
        self._report.add("[Charts placeholder]")

    def get_result(self) -> Report:
        return self._report


class Director:
    def __init__(self, builder: ReportBuilder) -> None:
        self._builder = builder

    def build_minimal_report(self, title: str) -> Report:
        self._builder.reset()
        self._builder.add_title(title)
        return self._builder.get_result()

    def build_full_report(self, title: str, summary: str) -> Report:
        self._builder.reset()
        self._builder.add_title(title)
        self._builder.add_summary(summary)
        self._builder.add_charts()
        return self._builder.get_result()


# Client code
builder = PlainTextReportBuilder()
director = Director(builder)

minimal = director.build_minimal_report("Q2 Report")
print(minimal.render())

full = director.build_full_report("Q2 Report", "Growth +15%")
print(full.render())