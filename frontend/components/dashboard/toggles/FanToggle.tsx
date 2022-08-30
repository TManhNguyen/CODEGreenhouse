import GenericToggle from './GenericToggle';

type Props = {
  enabled: boolean
  onClick: any
}

const FanToggle = ({
  enabled,
  onClick
}: Props) => {
  return (  
    <GenericToggle title="Fan" isOn={enabled} onClick={onClick}>
      <svg xmlns="http://www.w3.org/2000/svg" className="h-9 w-9 fill-current" viewBox="0 0 24 24">
        <path d="M11 10h-11v-2h11c.552 0 1-.448 1-1s-.448-1-1-1c-.403 0-.747.242-.905.587l-1.749-.956c.499-.965 1.494-1.631 2.654-1.631 3.971 0 3.969 6 0 6zm7 7c0-1.656-1.344-3-3-3h-15v2h15c.552 0 1 .448 1 1s-.448 1-1 1c-.403 0-.747-.242-.905-.587l-1.749.956c.499.965 1.494 1.631 2.654 1.631 1.656 0 3-1.344 3-3zm1.014-7.655c.082-.753.712-1.345 1.486-1.345.827 0 1.5.673 1.5 1.5s-.673 1.5-1.5 1.5h-20.5v2h20.5c1.932 0 3.5-1.568 3.5-3.5s-1.568-3.5-3.5-3.5c-1.624 0-2.977 1.116-3.372 2.617l1.886.728z"/>
      </svg>
    </GenericToggle>
  ) 
}

export default FanToggle