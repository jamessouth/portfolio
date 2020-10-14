[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type state =
| LoadingImg
| LoadedImg(string)
| Error(string);

let useFetch = (start, path) => {
    let (state, setState) = React.useState(() => LoadingImg);

    React.useEffect1(() => {
      if (start) {
        // if (path == "test") {
        //   setState(_ => LoadedImg(path));
        // } else if (path == "error") {
        //   setState(_ => Error(""));
        // } else {
          Js.Promise.(
            fetch(path)
              |>then_(response => {
                  if (response##ok) {
                    setState(_ => LoadedImg(response##url));
                  } else {
                    setState(_ => Error(""));
                    Js.log("failed to fetch " ++ response##url);
                  }
                  Js.Promise.resolve();
                })
              |>catch(_err => {
                setState(_ => Error(""));
                Js.log2("failed to fetch: ", _err);
                Js.Promise.resolve();
              })
              |>ignore
          );
        // }
      }
      None;
    }, [|start|]);

    state;
};