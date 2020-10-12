open Jest;
open ReactTestingLibrary;
open JestDom;

describe("Project", () => {
  let rendered = render(<Project
                          title="myProj"
                          live=Some("here")
                          code="there"
                          alt="cards"
                          text="long string"
                          liveAria="go to live"
                          codeAria="go to code"
                          path="test"
                          i=7
                          obPos="center"
                        />);

  test("displays correct title text", () => {
    rendered
    |> getByRole(~matcher=`Str("heading"), _)
    |> expect
    |> toHaveTextContent(`Str("myProj"), _)
  });

  test("2 links with live site", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    render(<p role="para">{linkArr->Array.length->React.int}</p>)
    |> getByRole(~matcher=`Str("para"), _)
    |> expect
    |> toHaveTextContent(`Str("2"), _)
  });

  test("live link has correct href", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    linkArr[1]
    |> expect
    |> toHaveAttribute("href", ~value="here")
  });

    test("1 link if no live site", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=None
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    render(<p role="para">{linkArr->Array.length->React.int}</p>)
    |> getByRole(~matcher=`Str("para"), _)
    |> expect
    |> toHaveTextContent(`Str("1"), _)
  });

    test("code link has correct href", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    linkArr[0]
    |> expect
    |> toHaveAttribute("href", ~value="there")
  });

  test("has correct alt", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("alt", ~value="cards")
  });


  test("displays correct body text", () => {
    let rendered = render(<Project
                            title="myProj"
                            live=Some("here")
                            code="there"
                            alt="cards"
                            text="long string"
                            liveAria="go to live"
                            codeAria="go to code"
                            path="test"
                            i=7
                            obPos="center"
                          />);

    rendered
    |> getByRole(~matcher=`Str("text"), _)
    |> expect
    |> toHaveTextContent(`Str("long string"), _)
  });

  // test("has correct offset position", () => {
  //   let rendered = render(<Article
  //                           link="blog.org"
  //                           alt="a book"
  //                           obPos={-90}
  //                           title="my article"
  //                           src="art.png"
  //                         />);

  //   rendered
  //   |> getByRole(~matcher=`Str("img"), _)
  //   |> expect
  //   |> toHaveStyle(`Obj({"object-position": "0 -90px"}))
  // });
});
